#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct Employee {
    int emp_id; // emp_ids will be unique
    char* emp_name;
    int emp_salary;
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};
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
void print_company_helper(struct Employee* ceo) {
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
struct Node
{
    int data;
    struct Node* next;
};
// create a node with data as x
struct Node* create_node(int x) {
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}
// delete the node at `ptr` and free its memory
void delete_node(struct Node* ptr) {
    free(ptr);
}
// --------------------------------------------------- YOU CAN EDIT BELOW THIS LINE -----------------------------------
struct Node* PythonListHead = NULL;
struct Employee* CEO = NULL;
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
void clear() { 
    struct Node* n1 = PythonListHead;
    struct Node* n2 = NULL;
    if(n1->next == NULL){
        delete_node(n1);
        PythonListHead = NULL;
    }
    else{
        while(n1->next != NULL){
        n2 = n1;
        n1 = n1->next;
        delete_node(n2);
        }
        delete_node(n1);
        PythonListHead = NULL;
    }
}    
int len() {
    // your code goes here
    if(PythonListHead == NULL){
        return(0);
    }
    else{
    struct Node* n = PythonListHead;
    int count;
    if(PythonListHead == NULL){
        count = 0;
    }
    else{
        count = 1;
    }
    while(n->next != NULL){
        n = n->next;
        count+=1;}
    return count;
}
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
int getitem(int position) {
    // your code goes here
    if(len()<=position){
    return -1;
    }
    else{
        struct Node* n1 = PythonListHead;
        for(int i = 0;i<position;i++){
            n1 = n1->next;
        }
        return(n1->data);
    }

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
void append(int x) {
    struct Node* n1 = create_node(x);
    if (PythonListHead == NULL){
        PythonListHead = n1;
    }
    else{
        struct Node* n2 = PythonListHead;
        while(n2->next != NULL)
            n2 = n2->next;
        n2->next = n1;
    }
}
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
int get_first_common_boss(int emp_id1,int emp_id2){
    if(emp_id1 == emp_id2){
        return (Boss(emp_id1));
    }
    int value = lca(CEO,pv(CEO,emp_id1),pv(CEO,emp_id2))->emp_id;
    return value;
}
void same_last_name_helper(struct Employee* ceo,int emp_id) {
    if(ceo == NULL) {
        return;
    }
    if(strcmp(ceo->emp_name,pv(CEO,emp_id)->emp_name)==0){
        append(ceo->emp_id);
    }
    same_last_name_helper(ceo->subordinate_1,emp_id);
    same_last_name_helper(ceo->subordinate_2,emp_id);
    return;
}
void same_last_names(int emp_id){
    same_last_name_helper(CEO,emp_id);
    for(int i =0 ; i<high(CEO);i++){
        for(int j = 0; j<len(); j++){
            if(Level(getitem(j)) == i){
                printf("%d ", getitem(j));
            }
        }
    }
    clear();
    return;
}
void get_all_bosses_helper(int emp_id){
    if(emp_id == CEO->emp_id){
        return;
    }
    get_all_bosses_helper(Boss(emp_id));
    printf("%d ",Boss(emp_id));
    return;
}
void get_all_bosses(int emp_id){
    if(emp_id == CEO->emp_id){
        printf("%d",-1);
    }
    else{
        get_all_bosses_helper(emp_id);
    }
    
}
int TeamSize(int emp_id) {
    if(emp_id>0){
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
return 0; 
}
int ssize = 0;
void subordinate_size_helper(struct Employee* ceo){
    if(ceo == NULL) {
        return;
    }
    ssize = ssize+1;
    subordinate_size_helper(ceo->subordinate_1);
    subordinate_size_helper(ceo->subordinate_2);
    return ;
}
double summation;

void get_average_salary_helper(struct Employee* ceo){
    if(ceo == NULL) {
        return;
    }
    summation = summation + ceo->emp_salary;
    get_average_salary_helper(ceo->subordinate_1);
    get_average_salary_helper(ceo->subordinate_2);
    return;

}
// float rounder(float var)
// {
//     float value = (int)(var * 100 + .5);
//     return (float)value / 100;
// }
double get_average_salary(int emp_id){
    summation = 0;
    ssize = 0;
    subordinate_size_helper(pv(CEO,emp_id));
    get_average_salary_helper(pv(CEO,emp_id));
    double average = summation/ssize;
    return average;
}
// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------
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
