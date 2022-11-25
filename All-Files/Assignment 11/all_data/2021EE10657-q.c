#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int x) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = x;
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int x;
    scanf("%d", &x);

    if(x == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present
    struct Employee* par = create_employee(x);

    par->subordinate_1 = create_company();
    par->subordinate_2 = create_company();
    
    return par;
}

// The following function 
void print_company_helper(struct Employee* ceo) {
    // take input
    if(!ceo) {
        printf("%d ", -1);
        return;
    }
    printf("%d ", ceo->emp_id);
    print_company_helper(ceo->subordinate_1);
    print_company_helper(ceo->subordinate_2);
    return;
}

void print_company(struct Employee* ceo) {
    print_company_helper(ceo);
    printf("\n");
    return;
} 

// --------------------------------------------------- YOU CAN EDIT BELOW THIS LINE -----------------------------------

struct Employee* CEO = NULL;
// CEO is a global pointer that points to the CEO of the company


// The following function returns the level of a employee with the given emp_id
int level_helper(struct Employee* ceo, int emp_id, int level)
{
    if(ceo==NULL){
        return 0;
    }
    if(ceo->emp_id==emp_id)
    {
        return level;
    }
    int x=level_helper(ceo->subordinate_1,emp_id,level++);
    if(x!=0)
    {
        return x+1;
    }
    x=level_helper(ceo->subordinate_2,emp_id,level++);
    return x;
}

int Level(int emp_id) {
    // Note that ceo has level 0
    struct Employee* ceo=CEO;
    int curlev=level_helper(ceo,emp_id,1)-1;
    return curlev;
}

/*  In this function you have to print all the employees at a given level, Note that ceo is at level 0
In any of the functions which involve printing you need not print -1 for NULL pointers */

void EmployeesAtSameLevel_helper(struct Employee* ceo, int curlev, int level)
{
    if(ceo==NULL)
    {
        return;
    }
    if(curlev==level)
    {
        printf("%d ",ceo->emp_id);
        return;
    }
    EmployeesAtSameLevel_helper(ceo->subordinate_1,curlev+1,level);
    EmployeesAtSameLevel_helper(ceo->subordinate_2,curlev+1,level);
}
void EmployeesAtSameLevel(int level) {
    // The level may be any integer
    struct Employee* ceo=CEO;
    EmployeesAtSameLevel_helper(ceo,0,level);
    return;
}

// You have to print the employees as you search the organization look for the examples in the pdf and the input.txt and output.txt for details
// Note: You do not have to print -1 for NULL pointers

void get_employees_helper(struct Employee* ceo) {
    // take input
    if(ceo!=NULL) { 
        printf("%d ", ceo->emp_id);
        get_employees_helper(ceo->subordinate_1);
        get_employees_helper(ceo->subordinate_2);
        return;
    }
}
void get_employees() {
    struct Employee* ceo = CEO;
    get_employees_helper(ceo);
    return;
}

/* In the following function you have to print the immediate team of a employee - it includes their boss and their subordinates
Note: You do not have to print -1 for NULL pointers */

void ImmediateTeam_helper(struct Employee* ceo, int emp_id)
{
    if(ceo==NULL)
    {
        return;
    }
    if(ceo->subordinate_1!=NULL)
    {
        struct Employee* p=ceo->subordinate_1;
        if(p->emp_id==emp_id)
        {
            printf("%d ",ceo->emp_id);
            struct Employee* q=p->subordinate_1;
            struct Employee* r=p->subordinate_2;
            if(q!=NULL)
            {
                printf("%d ",q->emp_id);
            }
            if(r!=NULL)
            {
                printf("%d ",r->emp_id);
            }
            return;
        }
    }
    if(ceo->subordinate_2!=NULL)
    {
        struct Employee* p=ceo->subordinate_2;
        if(p->emp_id==emp_id)
        {
            printf("%d ",ceo->emp_id);
            struct Employee* q=p->subordinate_1;
            struct Employee* r=p->subordinate_2;
            if(q!=NULL)
            {
                printf("%d ",q->emp_id);
            }
            if(r!=NULL)
            {
                printf("%d ",r->emp_id);
            }
            return;
        }
    }
    ImmediateTeam_helper(ceo->subordinate_1, emp_id);
    ImmediateTeam_helper(ceo->subordinate_2, emp_id);
    return;
}

void ImmediateTeam(int emp_id) {
    struct Employee* ceo=CEO;
    if(ceo->emp_id==emp_id)
    {
        struct Employee* q=ceo->subordinate_1;
        struct Employee* r=ceo->subordinate_2;
        if(q!=NULL)
        {
            printf("%d ",q->emp_id);
        }
        if(r!=NULL)
        {
            printf("%d ",r->emp_id);
        }
        return;
    }
    ImmediateTeam_helper(ceo,emp_id);
    return;
}


// The following function gives the distance between employees with emp_id1 and emp_id2
struct Employee* first_boss(struct Employee* ceo, int emp_id1, int emp_id2)
{
    if(ceo == NULL)
    {
        return NULL;
    }
    if(ceo->emp_id==emp_id1 || ceo->emp_id==emp_id2)
    {
        return ceo;
    }
    struct Employee* sub_boss1=first_boss(ceo->subordinate_1,emp_id1,emp_id2);
    struct Employee* sub_boss2=first_boss(ceo->subordinate_2,emp_id1,emp_id2);
    if(sub_boss1 && sub_boss2)
    {
        return ceo;
    }
    else if(sub_boss1 != NULL)
    {
        return sub_boss1;
    }
    else
    {
        return sub_boss2;
    }
}

int Distance(int emp_id1, int emp_id2) {
    // If emp_id1 and emp_id2 are equal the distance is 0, both emp_id's will exist in the organisation
    struct Employee* ceo = CEO;
    struct Employee* p = first_boss(ceo, emp_id1, emp_id2);
    int x=Level(p->emp_id);
    // printf("%d",x);
    int d=(Level(emp_id1)+Level(emp_id2)-(2*x));

    return d;
}

/* The following function takes an emp_id this will belong to a employee in the organisation and your task is to return the emp_id of its boss
Note: If the boss does not exit return -1 */
int Boss_helper(struct Employee* ceo, int emp_id,int boss)
{
    if(ceo == NULL) 
    {
        return -1 ;
    }
    if(ceo->emp_id==emp_id)
    {
        return boss;
    }
    else
    {
        
        int a = Boss_helper(ceo->subordinate_1,emp_id,ceo->emp_id);
        if (a != -1){
            return a;
        }
        a = Boss_helper(ceo->subordinate_2,emp_id,ceo->emp_id);
        if (a != -1){
            return a;
        }
        return -1;
       
    }
}

int Boss(int emp_id) {
    struct Employee* ceo =CEO;
    int boss=Boss_helper(ceo,emp_id,-1);
    return boss;
}

/* The following function returns the diameter of a Organisation - 
a diameter is the maximum distance between any two emp_ids in the organisation. You can use the distance function implemented above */

int max(int a, int b)
{
    int x;
    if(a>=b)
    {
        x=a;
    }
    else if(b>a)
    {
        x=b;
    }
    return x;
}
int maxlevel(struct Employee* ceo)
{
    int l;
    if(ceo==NULL)
    {
        return 0;
    }
    int leftmax=maxlevel(ceo->subordinate_1);
    int rightmax=maxlevel(ceo->subordinate_2);
    l=max(1+leftmax,1+rightmax);
    return l;
}
int Diameter_helper(struct Employee* ceo)
{
    if(ceo==NULL)
    {
        return 0;
    }
    int leftmax=maxlevel(ceo->subordinate_1);
    int rightmax=maxlevel(ceo->subordinate_2);
    int dialeft=Diameter_helper(ceo->subordinate_1);
    int diaright=Diameter_helper(ceo->subordinate_2);
    
    int d=max((1+leftmax+rightmax),max(dialeft,diaright));
    return d;
}
int Diameter() {
    struct Employee* ceo=CEO;
    int dia=Diameter_helper(ceo)-1;

    return dia;
}

/* The following function takes an emp_id of a employee and returns the number of employees directly connected to it.
NULL pointers are not included */

int TeamSize_helper(struct Employee*ceo, int emp_id)
{
    if(ceo==NULL)
    {
        return 0;
    }
    if(ceo->emp_id==emp_id)
    {
        if(Level(ceo->emp_id)!=0)
        {
            struct Employee* p=ceo->subordinate_1;
            struct Employee* q=ceo->subordinate_2;
            if(p!=NULL && q!=NULL)
            {
                return 3;
            }
            else if(p!=NULL || q!=NULL)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
        else
        {
           struct Employee* p=ceo->subordinate_1;
            struct Employee* q=ceo->subordinate_2;
            if(p!=NULL && q!=NULL)
            {
                return 2;
            }
            else if(p!=NULL || q!=NULL)
            {
                return 1;
            }
            else
            {
                return 0;
            } 
        }
    }
    int x=TeamSize_helper(ceo->subordinate_1,emp_id);
    if(x!=0)
    {
        return x;
    }
    x=TeamSize_helper(ceo->subordinate_2,emp_id);
    return x;
}
int TeamSize(int emp_id) {
    struct Employee* ceo=CEO;
    return TeamSize_helper(ceo,emp_id);
}

// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------

/* The following driver code creates a organisation for you and based on the input file
it will call all the functions that are necessary, your job is to edit the functions
above the line. Their descriptions are in the pdf and in the comments in the code. */

int main(int argc, char const *argv[])
{
    CEO = create_company();
    print_company(CEO);

    int T; 
    scanf("%d", &T);

    char operation_type[50];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "level") == 0) {
            int x;
            scanf("%d", &x);
            int d = Level(x);
            printf("%d\n", d);
        } 

        if(strcmp(operation_type, "distance") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            int d = Distance(x, y);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "employees_at_same_level") == 0) {
            int x;
            scanf("%d", &x);
            EmployeesAtSameLevel(x);
            printf("\n");
        }

        if(strcmp(operation_type, "get_employees") == 0) {
            get_employees();
            printf("\n");
        }

        if(strcmp(operation_type, "boss") == 0) {
            int x;
            scanf("%d", &x);
            int d = Boss(x);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "diameter") == 0) {
            int d = Diameter();
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "immediate_team") == 0) {
            int x;
            scanf("%d", &x);
            ImmediateTeam(x);
            printf("\n");
        }

        if(strcmp(operation_type, "team_size") == 0) {
            int x;
            scanf("%d", &x);
            int d = TeamSize(x);
            printf("%d\n", d);
        }
    }

    return 0;
}
