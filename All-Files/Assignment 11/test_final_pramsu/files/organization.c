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
// ------------------------------------------------------ IMPORTING LINKED LISTS --------------------------------------

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

// ------------------------------ Node struct definition ends here ------------------------------

// Use this to operate on the list, this will always point at the head of the list.
struct Node* PythonListHead = NULL;

// prints the list in space seperated format
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    //printf("\n");
}

// helper function that returns pointer to `Node` at `position`
// if there is no such position, it returns NULL
struct Node* get_node_at_pos(int position) {
    int pos = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        if(pos == position) return cur;
        pos++;
        cur = cur->next;
    }
    return NULL;
}

// Return the number of elements in the list
int len() {
    int length = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        length++;
        cur = cur->next;
    }
    return length;
}

// Add an item to the end of the list
void append(int x) {
    struct Node* cur = PythonListHead;
    if(cur == NULL) {
        // no list exists, we have to create one
        PythonListHead = create_node(x);
    }
    else {
        int pos = len() - 1;
        struct Node* last_node = get_node_at_pos(pos);
        last_node->next = create_node(x);
    }
}

// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    int n = len();
    if(position >= n) return;
    struct Node* node_at_position = get_node_at_pos(position);
    // 2 cases now
    // if node_at_position is the first node
    if(position == 0) {
        struct Node* new_node = create_node(x);
        new_node->next = node_at_position;
        PythonListHead = new_node;
    }
    else { // node_at_position is not the first node
        struct Node* previous_node = get_node_at_pos(position-1);
        previous_node->next = create_node(x);
        previous_node->next->next = node_at_position;
    }
}

// Remove the item at the end of the list
void pop() {
    int n = len();
    if(n == 0) return;

    if(n == 1) {
        delete_node(PythonListHead);
        PythonListHead = NULL;
    }
    else {
        struct Node* second_last_node = get_node_at_pos(n-2);
        delete_node(second_last_node->next);
        second_last_node->next = NULL;
    }
}

// Remove all items from the list
void clear() {
    struct Node* cur = PythonListHead;
    PythonListHead = NULL;
    while(cur) {
        struct Node* next_node = cur->next;
        delete_node(cur);
        cur = next_node;
    }
}

// Return the number of times x appears in the list.
int count(int x) {
    struct Node* cur = PythonListHead;
    int cnt = 0;
    while(cur) {
        if(cur->data == x) cnt++;
        cur = cur->next;
    }
    return cnt;
}

struct Node* reverse_helper(struct Node* cur_node) {
    if(cur_node == NULL) return NULL;

    if(cur_node->next == NULL) {
        // this is the first node of the reversed list
        PythonListHead = cur_node;
        return cur_node;
    }

    // recursively solve for the next node
    struct Node* next_node = reverse_helper(cur_node->next);

    // set the next of next_node to cur_node
    next_node->next = cur_node;

    // also make the cur_node->next as NULL, since cur_node is the last node of the list
    cur_node->next = NULL;

    return cur_node;
}

// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* last_node = reverse_helper(PythonListHead);
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(node_at_pos) {
        node_at_pos->data = x;
    }
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(node_at_pos) {
        return node_at_pos->data;
    }
    else return -1;
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(!node_at_pos) return;

    // 2 cases now
    // if node_at_pos is the first node
    if(node_at_pos == PythonListHead) {
        PythonListHead = PythonListHead->next;
        delete_node(node_at_pos);
    }
    else {
        struct Node* previous_node = get_node_at_pos(position-1);
        previous_node->next = node_at_pos->next;
        delete_node(node_at_pos);
    }
}


// Returns a the head of the newly formed Python List
// containing elements present in positions in the original List.
// Note: you have to create new Python List and return its head.
// Here positions is an array of size n.
// eg. if positions = [2, 3, 5], you need to return a newly formed list
// having nodes that were at position 2, 3 and 5 in the original list.
// if there is such a position that is not present in the original list, do nothing
// with that position.
struct Node* index_into(int *positions, int n) {
    // your code goes here
    struct Node* new_list_head = NULL;
    struct Node* new_list_tail = NULL;
    for(int i=0;i<n;i++) {
        struct Node* node_at_pos = get_node_at_pos(positions[i]);

        if(!node_at_pos) continue;

        if(new_list_tail) {
            new_list_tail->next = create_node(node_at_pos->data);
            new_list_tail = new_list_tail->next;
        }
        else {
            new_list_head = create_node(node_at_pos->data);
            new_list_tail = new_list_head;
        }
    }
    return new_list_head;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    struct Node* next_node = get_node_at_pos(position+1);
    if(!node_at_pos || !next_node) return;

    // 2 cases 
    if(node_at_pos == PythonListHead) {
        PythonListHead = next_node;
        node_at_pos->next = next_node->next;
        next_node->next = node_at_pos;
    }
    else {
        struct Node* prev_node = get_node_at_pos(position-1);
        prev_node->next = next_node;
        node_at_pos->next = next_node->next;
        next_node->next = node_at_pos;
    }
}


// sort the Python list via bubble sort
void sort() {
    int n = len();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            int x = get_node_at_pos(j)->data;
            int y = get_node_at_pos(j+1)->data;
            if(x > y) swap(j);
        }
    }
}

// --------------------------------------------- PROGRAM STARTS HERE ----------------------------------------------------------

struct Employee* CEO = NULL;
// CEO is a global pointer that points to the CEO of the company

int Boss();
// Helper function to traverse across the binary tree and return pointer for any given employee id
struct Employee* traversal(struct Employee* head, int emp_id)
{
    if (!head) return NULL;

    if (head->emp_id == emp_id) return head;
    if(traversal(head->subordinate_1,emp_id)!=NULL)
    {
        return(traversal(head->subordinate_1,emp_id));
    }
    if(traversal(head->subordinate_2,emp_id)!=NULL)
    {
        return(traversal(head->subordinate_2,emp_id));   
    }
    return NULL;
}

/*  In this function you have to print all the employees at a given level, Note that ceo is at level 0
In any of the functions which involve printing you need not print -1 for NULL pointers */

// Helper function for EmployeesAtSameLevel function
void EmployeesAtSameLevelHelper(struct Employee* ptr, int count, int level) {
    if (ptr == NULL) return;
    if (count == level) append(ptr->emp_id);
    
    count++;
    EmployeesAtSameLevelHelper(ptr->subordinate_1,count,level);
    EmployeesAtSameLevelHelper(ptr->subordinate_2,count,level);
    return;
}

void EmployeesAtSameLevel(int level) {
    // The level may be any integer (Invalid level-- Empty Line Printed by Driver Code)
    EmployeesAtSameLevelHelper(CEO, 0, level);
    if(len() == 0) return;
    print_list(PythonListHead);
    clear();
    return;
}

// You have to print the employees as you search the organization look for the examples in the pdf and the input.txt and output.txt for details
// Note: You do not have to print -1 for NULL pointers

// Helper function for get_employees function
void get_employees_helper(struct Employee* ptr) {
    if(!ptr) return;
    printf("%d ", ptr->emp_id);
    get_employees_helper(ptr->subordinate_1);
    get_employees_helper(ptr->subordinate_2);
    return;
}

void get_employees() {
    struct Employee* head = CEO; 
    get_employees_helper(head);
    return;
}

/* In the following function you have to print the immediate team of a employee - it includes their boss and their subordinates
Note: You do not have to print -1 for NULL pointers */

void ImmediateTeam(int emp_id) {
    struct Employee* head = traversal(CEO, emp_id);
    int boss = Boss(emp_id);
    int sub1 = 0, sub2 = 0;

    if(head->subordinate_1 != NULL) sub1 = head->subordinate_1->emp_id;
    if(head->subordinate_2 != NULL) sub2 = head->subordinate_2->emp_id;
    
    if(boss != -1)
    {
        if (head->subordinate_1 != NULL && head->subordinate_2 != NULL)
        printf("%d %d %d ", boss, sub1, sub2);  
        else if (head->subordinate_1 == NULL && head->subordinate_2 != NULL) 
        printf("%d %d ", boss, sub2);
        else if (head->subordinate_2 == NULL && head->subordinate_1 != NULL) 
        printf("%d %d ", boss, sub1);
        else printf("%d ", boss);  
    }

    else  
    {
        if (head->subordinate_1 != NULL && head->subordinate_2 != NULL)
        printf("%d %d ", sub1, sub2);  
        else if (head->subordinate_1 == NULL && head->subordinate_2 != NULL) 
        printf("%d ", sub2);
        else if (head->subordinate_2 == NULL && head->subordinate_1 != NULL) 
        printf("%d ", sub1);
    }
    return;
} 

int level_helper(struct Employee* head, struct Employee* ptr){
    if(head == ptr) return 1;
    if(head == NULL) return 0;

    int m = level_helper(head->subordinate_1,ptr);
    int n = level_helper(head->subordinate_2,ptr);
    
    if (m == 0 && n != 0) return (n+1);
    else if (m != 0 && n == 0) return (m+1);
    else return 0;
}

// The following function returns the level of a employee with the given emp_id
int Level(int emp_id) {
    struct Employee* head = traversal(CEO, emp_id);
    return (level_helper(CEO ,head)-1);
}

// Helper function for Distance function
void path(int emp_id1, int emp_id2) {
    append(emp_id1);
    while(Boss(emp_id1) != -1)
    {
        int b = Boss(emp_id1);
        append(b);
        emp_id1 = b;
    }

    append(-1);
    int n = len();

    append(emp_id2);
    while(Boss(emp_id2) != -1)
    {
        int b = Boss(emp_id2);
        append(b);
        emp_id2 = b;
    }
    reverse();
    return;
}

// Helper function for Distance function
int least_common_ancestor(int emp_id1, int emp_id2) {
    path(emp_id1,emp_id2);
    int mark = 0;
    int lcr = 0;

    for (int i = 0; i < len(); i++)
    {
        if(getitem(i)==-1)
        {
            mark = i;
            break;
        }
    }
    
    int size1 = mark;
    int size2 = len()-mark-1;
    
    for (int i = 0; i < size1 && i < size2 ; i++)
    {
        if (getitem(i) != getitem(i+mark+1)) break;
        lcr = getitem(i);
    }
    clear();   
    return lcr;
}

// The following function gives the distance between employees with emp_id1 and emp_id2
int Distance(int emp_id1, int emp_id2) {
    // If emp_id1 and emp_id2 are equal the distance is 0, both emp_id's will exist in the organisation
    int lcr = least_common_ancestor(emp_id1, emp_id2);
    int level_lcr = Level(lcr);
    int level_emp1 = Level(emp_id1);
    int level_emp2 = Level(emp_id2);
    
    level_emp1 = level_emp1 - level_lcr;
    level_emp2 = level_emp2 - level_lcr;
    return (level_emp1+level_emp2);
}

int boss_helper(struct Employee* head, struct Employee* ptr) {
    if (head->subordinate_1 == ptr || head->subordinate_2 == ptr) return (head->emp_id);
    
    if(head->subordinate_1 == NULL && head->subordinate_2 == NULL) return -1;
    else if(head->subordinate_1 == NULL) return boss_helper(head->subordinate_2,ptr);
    else if(head->subordinate_2 == NULL) return boss_helper(head->subordinate_1,ptr);

    int m = boss_helper(head->subordinate_1,ptr);
    int n = boss_helper(head->subordinate_2,ptr);
    
    if (m == -1 && n != -1) return (n);
    else if (m != -1 && n == -1) return (m);
    else return -1;
}

/* The following function takes an emp_id this will belong to a employee in the organisation and your task is to return the emp_id of its boss
Note: If the boss does not exit return -1 */
int Boss(int emp_id) {
    struct Employee* head = traversal(CEO, emp_id);
    return boss_helper(CEO, head);
}

/* The following function returns the diameter of a Organisation - 
a diameter is the maximum distance between any two emp_ids in the organisation. You can use the distance function implemented above */

// Helper function for Diameter
void possible_interns(struct Employee* head) {
    if (head->subordinate_1 == NULL && head->subordinate_2 == NULL)
    {
        append(head->emp_id);
        return;
    }
    else if (head->subordinate_1 != NULL && head->subordinate_2 == NULL) possible_interns(head->subordinate_1);
    else if (head->subordinate_1 == NULL && head->subordinate_2 != NULL) possible_interns(head->subordinate_2);
    else
    {
        possible_interns(head->subordinate_1);
        possible_interns(head->subordinate_2);
    }
    return;
}

int Diameter() {
    possible_interns(CEO);
    append(CEO->emp_id);
    //print_list(PythonListHead);

    // Copy the contents in an array
    int k = len();
    int dia = 0;

    int interns[k];

    for (int i = 0; i < k; i++)
    {
        interns[i] = getitem(i);
    }
    clear();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int temp = Distance(interns[i],interns[j]);
            if (temp > dia) dia = temp;
        }
    }
    return dia;
}

/* The following function takes an emp_id of a employee and returns the number of employees directly connected to it.
NULL pointers are not included */

int TeamSize(int emp_id) {
    struct Employee* top = traversal(CEO,emp_id);
    int count = 0;
    if (Boss(emp_id) != -1) count++;
    if (top->subordinate_1 != NULL) count++;
    if (top->subordinate_2 != NULL) count++;
    return count;
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
