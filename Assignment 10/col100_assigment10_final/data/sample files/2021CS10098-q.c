#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
int len();

// prints the list in space seperated format
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


// Add an item to the end of the list
void append(int x) {
    struct Node* temp = PythonListHead;
    struct Node* add = create_node(x);
    if(temp==NULL)
    {
        PythonListHead = add;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = add;
    return;
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    struct Node* temp = PythonListHead;
    int c=0;
    struct Node* add = create_node(x);
    if(temp==NULL)
    {
        if(position == 0)
        {
            PythonListHead = add;
            return;
        }
    }
    else if(position == 0)
    {
        PythonListHead = add;
        add->next = temp;
        return;
    }
    while(c<position-1 && temp->next!=NULL)
    {
        temp = temp->next;
        c++;
    }
    if(c==position-1 && temp->next == NULL)
    {
        temp->next = add;
        return;
    }
    else if(c==position-1)
    {
        struct Node* save = temp->next;
        temp->next = add;
        add->next = save;
        return;
    }
    return;
}


// Remove the item at the end of the list
void pop() {
    struct Node* temp = PythonListHead;
    if(temp == NULL) return;
    if(temp->next == NULL) {
        PythonListHead = NULL;
        return;
    }
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    struct Node* er = temp->next;
    temp->next = NULL;
    delete_node(er);
}

void clearALL(struct Node* head)
{
    if(head==NULL) return;
    if(head->next==NULL){
        return;
    }
    clearALL(head->next);
    if(head->next->next == NULL)
    {
        struct Node* temp = head->next;
        //temp->next = NULL;
        delete_node(temp);
    }
    
    head->next = NULL;
    //delete_node(head);
    return;
}

// Remove all items from the list
void clear() {
    clearALL(PythonListHead);
    if(PythonListHead!=NULL && PythonListHead->next == NULL)
    {
        delete_node(PythonListHead);
    }
    PythonListHead = NULL;
}


// Return the number of times x appears in the list.
int count(int x) {
    // your code goes here
    struct Node* temp = PythonListHead;
    int c=0;
    while(temp!=NULL)
    {
        if(temp->data == x)
        {
            c++;
        }
        temp= temp->next;
    }
    return c;
}


// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* p = PythonListHead;
    struct Node* temp = PythonListHead;
    if(temp==NULL || temp->next ==NULL)
    {
        return;
    }
    
    temp = temp->next;
    PythonListHead->next = NULL;
    struct Node* n = temp->next;
    
    while(n!=NULL)
    {
        
        temp->next = p;
        p = temp;
        temp = n;
        n = n->next;
        
    }
    temp->next = p;
    PythonListHead = temp;
}


// Return the number of elements in the list
int len() {
    // your code goes here
    if(PythonListHead == NULL){
        return 0;
    }
    int c=0;
    struct Node* temp = PythonListHead;
    while(temp!=NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
    //return 0;
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    int c=0;
    struct Node* temp = PythonListHead;
     if(c==position && temp!=NULL)
        {
            temp->data = x;
        }
    while(temp!=NULL)
    {
        if(c==position)
        {
            temp->data = x;
        }
        temp = temp->next;
        c++;
    }  
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    // your code goes here
    int c=0;
    if(c>= len() || c<0){
        return -1;
    }
    struct Node* temp = PythonListHead;
     if(c==position)
        {
            return temp->data;
        }
    while(temp!=NULL)
    {
        if(c==position)
        {
            return temp->data;
        }
        temp = temp->next;
        c++;
    }
    return -1;
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    struct Node* temp = PythonListHead;
    int c=0;
    if(temp==NULL)
    {
        return;
    }
    else if(position == 0)
    {
        PythonListHead = PythonListHead->next;
        delete_node(temp);
        return;
    }
    while(c<position-1 && temp->next!=NULL)
    {
        temp = temp->next;
        c++; 
    }
    if(c==position-1 && temp->next != NULL)
    {
        struct Node* t = temp->next;
        temp->next = temp->next->next;
        t->next = NULL;
        delete_node(t);
        return;
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
    struct Node* newHead =NULL;
    struct Node* temp=NULL;
    int x = getitem(positions[0]);
        if(x!=-1){
            newHead = create_node(x);
            temp = newHead;
        }
    else{
        newHead = NULL; 
    }
    for(int i=1; i<n; i++)
    {
        int x = getitem(positions[i]);
        if(x==-1){
            continue;
        }
        struct Node* add = create_node(x);
        if(temp==NULL)
        {
            temp = add;
            newHead = add;
            continue;
        }
        temp->next = add;
        temp = add;
    }
    return newHead;
    return NULL;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    int n = len();
    if(position <0 || position+1 >=n )
    {
        return;
    }
    int c = 0;
    struct Node* temp = PythonListHead;
    if(position == 0)
    {
        PythonListHead = temp->next;
        temp->next = PythonListHead->next;
        PythonListHead->next = temp;
        return;
    }
    while(c<position-1)
    {
        c++;
        temp=temp->next;
    }
    //printf("%d ", temp->data);
    struct Node* a = temp->next;
    temp->next = temp->next->next;
    a->next = temp->next->next;
    temp->next->next = a;
    
}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {
    int n = len();
    struct Node* tempi = PythonListHead;
    struct Node* tempj = PythonListHead;

    
    for(struct Node* tempi = PythonListHead; tempi!=NULL; tempi = tempi->next)
    {
        for(struct Node* tempj = tempi->next; tempj!=NULL; tempj = tempj->next)
        {
            int x = tempi->data;
            int y = tempj->data;
            if(x>y){
                tempi->data = y;
                tempj->data = x;
            }
        }
    }
}


// ----------------------- Driver program starts here -----------------------

int main(int argc, char const *argv[])
{
    int T; 
    scanf("%d", &T);

    char operation_type[20];
    int indices[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "append") == 0) {
            int x;
            scanf("%d", &x);
            append(x);
        } 

        if(strcmp(operation_type, "insert") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insert(pos, x);
        }

        if(strcmp(operation_type, "pop") == 0) {
            pop();
        }

        if(strcmp(operation_type, "clear") == 0) {
            clear();
        }

        if(strcmp(operation_type, "count") == 0) {
            int x;
            scanf("%d", &x);
            int cnt = count(x);
            printf("%d\n", cnt);
        }

        if(strcmp(operation_type, "reverse") == 0) {
            reverse();
        }

        if(strcmp(operation_type, "len") == 0) {
            int length = len();
            printf("%d\n", length);
        }

        if(strcmp(operation_type, "setitem") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            setitem(pos, x);
        }

        if(strcmp(operation_type, "getitem") == 0) {
            int pos;
            scanf("%d", &pos);
            int value = getitem(pos);
            printf("%d\n", value);
        }

        if(strcmp(operation_type, "print") == 0) {
            print_list(PythonListHead);
        }

        if(strcmp(operation_type, "erase") == 0) {
            int pos;
            scanf("%d", &pos);
            erase(pos);
        }

        if(strcmp(operation_type, "swap") == 0) {
            int pos;
            scanf("%d", &pos);
            swap(pos);
        }

        if(strcmp(operation_type, "index_into") == 0) {
            int n;
            scanf("%d", &n);
            for(int i=0;i<n;i++) scanf("%d", &indices[i]);
            struct Node* new_head = index_into(indices, n);
            print_list(new_head);
        }

        if(strcmp(operation_type, "sort") == 0) {
            sort();
        }
    }
}