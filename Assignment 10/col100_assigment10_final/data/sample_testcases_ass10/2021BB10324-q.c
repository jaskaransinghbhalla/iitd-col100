#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("\n");
}


// Add an item to the end of the list
void append(int x) {
    struct Node* new=create_node(x);
    struct Node* ptr = PythonListHead;
    if (ptr==NULL){
        PythonListHead=new;
        return;
    }

    
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next =new;
    
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    int i;
    struct Node* ptr = PythonListHead;
    struct Node* ptr2= create_node(x);
    if(ptr!=NULL){
        
        for(i=0;i<position-2;i++){
            ptr=ptr->next;
            if(ptr->next==NULL){
                return;
            }    
        }
        if(position!=0 ){
            ptr2->next=ptr->next;
            ptr->next=ptr2;
        }
        else{
            if(position==0){
            ptr2->next=ptr;
            PythonListHead=ptr2;
            }
        }
    }
}



// Remove the item at the end of the list
void pop() {
    struct Node* ptr=PythonListHead;
    struct Node* ptr2=PythonListHead;
    if(ptr!=NULL){
        while(ptr->next!=NULL){
            ptr2=ptr;
            ptr=ptr->next;
        }
        if(ptr2!=ptr){
            ptr2->next=NULL;
            ptr=NULL;
            free(ptr);
        }
        else{
            PythonListHead=NULL;
            free( PythonListHead);
        }

    }
}


// Remove all items from the list
void clear() {
    if(PythonListHead!=NULL){
        PythonListHead->next=NULL;
        PythonListHead=NULL;
        free(PythonListHead);
    }
}


// Return the number of times x appears in the list.
int count(int x) {
    struct Node *ptr = PythonListHead;
    int r=0;
    if (PythonListHead==NULL){
        return 0;
    }
    else{
        while(ptr!=NULL){
            if (ptr->data==x){
                r++;
            }
            ptr=ptr->next;
        }

    return r;
}
}

// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* ptr=PythonListHead;
    struct Node* ptr2=NULL;
    struct Node* ptr1=PythonListHead;
    while(ptr!=NULL){
        ptr1=ptr->next;
        ptr->next=ptr2;
        ptr2=ptr;
        ptr=ptr1;
    }
    PythonListHead=ptr2;
    
}


// Return the number of elements in the list
int len() {
    int i;
    struct Node* ptr=PythonListHead;
    i=1;
    if(ptr!=NULL){
    while(ptr->next!=NULL){
        ptr=ptr->next;
        i++;
    }
    return i;
    }
    else{
        return 0;
    }
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    struct Node* ptr=PythonListHead;
    int i;
    if(ptr!=NULL){
        if(position==0){
            PythonListHead->data=x; 
        }
        else{
        for(i=0;i<=position-2;i++){
            if(ptr->next!=NULL){
            ptr=ptr->next;
            }
        }
        ptr->data=x;
        }
    }
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    struct Node* ptr=PythonListHead;
    int i;
    if(ptr!=NULL){
        if(position==0){
            return PythonListHead->data;
        }
        else{
        for(i=0;i<=position-2;i++){
            if(ptr->next!=NULL){
            ptr=ptr->next;
            }
            else{
                return -1;
            }
        }
        return ptr->data;
        }
}
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    int i=0;
    struct Node* ptr=PythonListHead;
    struct Node* ptr1;
    if(ptr!=NULL){
        if(position==0){
            if(ptr->next==NULL){
            PythonListHead=NULL;
            free(PythonListHead);
            }
            else{
                PythonListHead=ptr->next;
            }
        }
        else{
        while(i<=position-2){
            if(ptr->next!=NULL){
                ptr1=ptr;
                ptr=ptr->next;
                i++;
            }
            else{
                return;
            }
        }
        ptr1->next=ptr->next;
        free(ptr);
        ptr=NULL;
    }
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
    struct Node* ptr=PythonListHead;
    int* ptr1=positions;
    struct Node* ptr2;
    struct Node* ptr3;
    int i=0;
    int k=0;
    for(i=0;i<=n-1;i++){
        while(k<*(ptr1)){
            ptr=ptr->next;
            if(ptr==NULL && i==0){
                return PythonListHead;
            }
            else{
                if(ptr!=NULL){
                    k++;
                }
                else{
                    break;
                }
            }
        }
        if(i==0){
            ptr2=ptr;
            ptr3=ptr2;
        }
        else{
            if(ptr2->next!=NULL){
            ptr2->next=ptr;
            ptr2=ptr;
            }
            else{
                break;
            }
        }
        ptr1=(ptr1+1);
    }
    if(ptr2!=NULL&&ptr!=NULL){
    ptr2->next=NULL;
    ptr->next=NULL;
    }
    return ptr3;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    int i=0;
    struct Node* ptr=PythonListHead;
    struct Node* ptr1=PythonListHead;
    struct Node* ptr2=PythonListHead;
    if(position==0){
        if(ptr->next!=NULL){
            ptr1=ptr;
            ptr2=ptr->next;
            PythonListHead=ptr2;
            ptr1->next=ptr2->next;
            ptr2->next=ptr;
            
        }
    }
    else{
    while(i<=position-2 && ptr->next!=NULL){
            ptr1=ptr;
            ptr2=ptr->next;
            ptr=ptr->next;
            i++;
        
    }
    if(ptr2!=NULL){
    ptr2=ptr2->next;
    if(ptr2!=NULL){
        ptr1->next=ptr2;
        ptr->next=ptr2->next;
        ptr2->next=ptr;
          
    }
    }
    }
}
// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you.
void sort(){
    
    int i=0;
    int n;
    struct Node* ptr=PythonListHead;
    struct Node* ptr1=PythonListHead;
    if(ptr!=NULL){
    struct Node* ptr2=ptr->next;
    while(ptr!=NULL){
         
         i++;
         ptr=ptr->next;
    }
    n=i;
    int j=1;
    int k=1;
    while(k<=n){
        
        while(j<n){
            if(ptr1->data>ptr2->data){
            swap(j);
            ptr2=ptr1->next;
            j++;
            }
            else{    
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            j++;
            }
        }
        j=1;
        ptr1=PythonListHead;
        ptr2=PythonListHead->next;
        k++;
    }
    }
    }



// ----------------------- Driver program starts here -----------------------

int main(int argc, char const *argv[]){
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