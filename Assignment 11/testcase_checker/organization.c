#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct Employee {
    int emp_id; // emp_ids will be unique
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};
struct Employee* create_employee(int x) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = x;
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}
struct Employee* create_company() {
    int x;
    scanf("%d", &x);

    if(x == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present
    struct Employee* par = create_employee(x);

    par->subordinate_1 = create_company();
    par->subordinate_2 = create_company();
    
    return par;
}
void print_company_helper(struct Employee* ceo) {
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
int csize = 0;
struct Employee* pv(struct Employee* p, int emp){
    if(p == NULL){
        return p;
    }
    else if(p->emp_id == emp) {
        return p;
        }
    else{
        if(pv(p->subordinate_1,emp) == NULL){
            return pv(p->subordinate_2, emp);
        }
        else{
        return pv(p->subordinate_1,emp);
        }
    }
}
struct Employee* lca(struct Employee* p1, struct Employee*p2, struct Employee* p3){
    if(p1 == NULL || p1 == p2 || p1 == p3){
        return p1;
    }
    struct Employee* l = lca(p1->subordinate_1,p2,p3);
    struct Employee* r = lca(p1->subordinate_2,p2,p3);
    if(l == NULL){
        return r;
        }
    else if(r == NULL){
        return l;
        }
    else if(l != NULL && r != NULL){
        return p1;
        }
    return p1;
    }
int Level_helper(struct Employee * temp, int data, int level){
    if(temp == NULL){
        return 0;
    }
    else if(temp->emp_id == data){
    return level;
    }
    int below = Level_helper(temp->subordinate_1,data,level+1);
    if(below != 0){
        return below;
    }
    below = Level_helper(temp->subordinate_2,data,level+1);
    return below;

}
int Level(int emp_id) {
    int level = 0;
    return Level_helper(CEO,emp_id,level);

}
void EmployeesAtSameLevel_helper(struct Employee* p,int level){
    if(p == NULL) {
        return;
    }
    if(Level(p->emp_id) == level){
        printf("%d ",p->emp_id);
    }
    EmployeesAtSameLevel_helper(p->subordinate_1,level);
    EmployeesAtSameLevel_helper(p->subordinate_2,level);
    return;
}
void EmployeesAtSameLevel(int level) {
    EmployeesAtSameLevel_helper(CEO,level);
    return;
}
void get_employees_helper(struct Employee* ceo) {
    // take input
    if(ceo == NULL) {
        return;
    }
    printf("%d ", ceo->emp_id);
    get_employees_helper(ceo->subordinate_1);
    get_employees_helper(ceo->subordinate_2);
    return;
}
void get_employees() {
    get_employees_helper(CEO);
    return;
}
void company_size_helper(struct Employee* ceo){
    if(ceo == NULL) {
        return;
    }
    csize = csize+1;
    company_size_helper(ceo->subordinate_1);
    company_size_helper(ceo->subordinate_2);
    return ;
}
int Distance(int emp_id1, int emp_id2) {

    struct Employee* Pointer1 = pv(CEO,emp_id1);
    struct Employee* Pointer2 = pv(CEO,emp_id2);
    struct Employee* Pointer3 = lca(CEO,Pointer1,Pointer2);

    int level1 = 0;
    int level2 = 0;
    return (Level_helper(Pointer3,emp_id1,level1) + Level_helper(Pointer3,emp_id2,level2));
    // If emp_id1 and emp_id2 are equal the distance is 0
    return 0;
}
int boss_helper(struct Employee* p, int emp_id) {
    int k1 = 0,k2 = 0;
    // take input
    if(p == NULL) {
        return -1;
    }
    if(p == CEO && p->emp_id==emp_id){
        return -1;
    }
    if(p->subordinate_1 != NULL){
        if(p->subordinate_1->emp_id == emp_id){
        return p->emp_id;}
        }
    if(p->subordinate_2 != NULL){
        if(p->subordinate_2->emp_id == emp_id){
        return p->emp_id;}
        }
    k1 = boss_helper(p->subordinate_1,emp_id);
    if(k1!=-1){
        return k1;
    }
    k2 = boss_helper(p->subordinate_2,emp_id);
    if(k2!=-1){
        return k2;
    }
    if(k1 == -1 && k2 == -1){
        return -1; 
    }
    return -1;
}
int Boss(int emp_id) {
    return boss_helper(CEO,emp_id);
}
void ImmediateTeam(int emp_id) {
    int sample = Boss(emp_id);
    if(sample!=-1){
        printf("%d ",sample);
    }
    
    struct Employee* p = pv(CEO,emp_id);
    if(p->subordinate_1 != NULL){
        printf("%d ",p->subordinate_1->emp_id);
    }
    if(p->subordinate_2 != NULL){
        printf("%d ", p->subordinate_2->emp_id);
    }
    

    return;
}
int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int high(struct Employee* p){
    if(p == NULL){
        return 0;
    }
    return (1 + max(high(p->subordinate_1),high(p->subordinate_2)));

}
int Diameter_helper(struct Employee *p){
    if(p == NULL){
        return 0;
    }
    int o1 = high(p->subordinate_1) + high(p->subordinate_2);
    int o2 = Diameter_helper(p->subordinate_1);
    int o3 = Diameter_helper(p->subordinate_2);
    return max(o1,max(o2,o3));
}
int Diameter() {
    int k = Diameter_helper(CEO);
    return k;
}
int TeamSize(int emp_id) {
    int count = 0;
    struct Employee* p = pv(CEO,emp_id);
    if(Boss(emp_id)!=-1){
        count++;
    }
    if(p->subordinate_1 != NULL){
        count++;
    }
    if(p->subordinate_2 != NULL){
        count++;
    }
    
    return count; 
}
// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------
int main(int argc, char const *argv[])
{
    CEO = create_company();
    print_company(CEO);

    int T; 
    scanf("%d", &T);

    char operation_type[50];

    company_size_helper(CEO);
    

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
