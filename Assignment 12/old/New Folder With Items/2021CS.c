#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    char* emp_name;
    int emp_salary;
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int id, char* name, int salary) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = id;
    ptr->emp_salary = salary;
    ptr->emp_name = strdup(name);
    // strdup() creates a copy of the string or char pointer and stores it in the new char pointer of the employee
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int id, salary;
    char name[100];
    scanf("%d", &id);
    if(id == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present

    scanf("%s %d", name, &salary);
    struct Employee* par = create_employee(id, name, salary);

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
    printf("%d %s %d ", ceo->emp_id, ceo->emp_name, ceo->emp_salary);
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

int levelhelp(struct Employee* head, int x)
{
    if(head==NULL)
    {
        return -1;
    }
    if(head->emp_id == x)
    {
        return 0;
    }
    int a = levelhelp(head->subordinate_1, x);
    int b = levelhelp(head->subordinate_2,x);
    if(a!=-1)
    {
        return a+1;
    }
    if(b!=-1)
    {
        return b+1;
    }
    return -1;
}

// The following function returns the level of a employee with the given emp_id
int Level(int emp_id) {
    // Note that ceo has level 0
    return levelhelp(CEO, emp_id);
    return 0;
}

int max(int x, int y)
{
    if(x>y) return x;
    return y;
}

int min(int x, int y)
{
    if(x>y) return x;
    else return y;
}


// CEO is a global pointer that points to the CEO of the company
int Boss(int emp_id);
struct Employee* LCA(struct Employee* root, int x, int y)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->emp_id == x || root->emp_id == y)
    {
        return root;
    }
    struct Employee* l = LCA(root->subordinate_1 , x, y);
    struct Employee* r = LCA(root->subordinate_2 , x, y);
    if(l!=NULL && r!=NULL)
    {
        return root;
    }
    if(l!=NULL && r==NULL)
    {
        return l;
    }
    if(r!=NULL && l==NULL)
    {
        return r;
    }
    return NULL;
}


// The below function returns the employee id of the first common boss
int get_first_common_boss(int emp_id1,int emp_id2){
    if(emp_id1 == emp_id2)
    {
        return Boss(emp_id1);
    }
    struct Employee* x = LCA(CEO, emp_id1, emp_id2);
    if(x!=NULL)
    {
        return x->emp_id;
    }
    return 0;
}

struct Employee* getNode(struct Employee* head, int x)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->emp_id == x)
    {
        return head;
    }
    struct Employee* l = getNode(head->subordinate_1, x);
    struct Employee* r = getNode(head->subordinate_2, x);
    if(l!=NULL) return l;
    if(r!=NULL) return r;
    return NULL;
}



void samelast(struct Employee* root, char* s, int level)
{
    if(root==NULL)
    {
        return;
    }
    if(strcmp(root->emp_name, s)==0 && Level(root->emp_id) == level)
    {
        printf("%d ", root->emp_id);
    }
    else if(Level(root->emp_id) < level)
    {
        samelast(root->subordinate_1, s, level);
        samelast(root->subordinate_2, s, level);
    }
    
}

int height(struct Employee* root)
{
    if(root==NULL) return 0;
    int l = height(root->subordinate_1);
    int r = height(root->subordinate_2);
    return max(l,r) + 1;
}
//Print the employees with the same last name sperated by a space in the order of their level
void same_last_names(int emp_id){
    struct Employee* e = getNode(CEO, emp_id);
    char* s = e->emp_name;
    int h = height(CEO);
    for(int i=0; i<h; i++)
    {
        samelast(CEO, s, i);
    }
    
    return;
}

int bosshelp(struct Employee* head, int x)
{
    if(head == NULL)
    {
        return -1;
    }
    if(head->subordinate_1 != NULL && head->subordinate_1->emp_id == x)
    {
        return head->emp_id;
    }
    if(head->subordinate_2 != NULL && head->subordinate_2->emp_id == x)
    {
        return head->emp_id;
    }
    int a = bosshelp(head->subordinate_1, x);
    int b = bosshelp(head->subordinate_2, x);
    if(a!=-1)
    {
        return a;
    }
    return b;
}

int Boss(int emp_id) {
    return bosshelp(CEO, emp_id);
    //return 0;
}

// Print the bosses of the given employee in the order from CEO to immediate boss
void getbosshelp(int emp_id)
{
    int x = Boss(emp_id);
    if(x==-1)
    {
        printf("%d ", emp_id);
        return;
    }
    getbosshelp(x);
    printf("%d ", emp_id);
}
void get_all_bosses(int emp_id){
    int x = Boss(emp_id);
    if(x==-1){
        printf("-1");
        return;
    }
    getbosshelp(x);
}
int count(struct Employee* root)
{
    if(root==NULL) return 0;
    int l = count(root->subordinate_1);
    int r = count(root->subordinate_2);
    return l+r+1;
}

double sum(struct Employee* root)
{
    if(root==NULL) return 0;
    int l = sum(root->subordinate_1);
    int r = sum(root->subordinate_2);
    //printf("%d , %d \n", root->emp_id, l+r+root->emp_salary);
    return l+r+root->emp_salary;
}
// Return the average salary of the team with the given employee as head
double get_average_salary(int emp_id){
    struct Employee* x = getNode(CEO, emp_id);
    double s = sum(x);
    double c = count(x);
    //printf("%d %d", (int)s, (int)c);
    return s/c;
    return 0.0;
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

    char operation_type[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "get_first_common_boss") == 0) {
            int x,y;
            scanf("%d %d", &x, &y);
            int ans = get_first_common_boss(x,y);
            printf("%d\n", ans);
        } 
        else if(strcmp(operation_type, "same_last_names") == 0) {
            int x;
            scanf("%d", &x);
            same_last_names(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_all_bosses") == 0) {
            int x;
            scanf("%d", &x);
            get_all_bosses(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_average_salary") == 0) {
            int x;
            scanf("%d", &x);
            double ans = get_average_salary(x);
            printf("%.2f\n", ans);
        } 

    }

    return 0;
}
