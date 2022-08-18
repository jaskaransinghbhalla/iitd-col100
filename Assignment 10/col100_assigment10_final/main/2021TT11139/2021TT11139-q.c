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
struct Node* PythonListHead1;
// prints the list in space seperated format
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
void append2(int x) {
    struct Node* n1 = create_node(x);
    if (PythonListHead1 == NULL){
        PythonListHead1 = n1;
    }
    else{
        struct Node* n2 = PythonListHead1;
        while(n2->next != NULL)
            n2 = n2->next;
        n2->next = n1;
    }
}
// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    if(len()==0){
        return;
    }
    else if(position == 0){
        struct Node* p = PythonListHead;
        struct Node* n2 = create_node(x);
        n2->next=p;
        PythonListHead = n2;

    }   
    else if(position>=len()) {
    }
    else{
        struct Node* n1 = PythonListHead;
        struct Node* n3 = PythonListHead;
        struct Node* n2 = create_node(x);
        for(int i = 0;i<position;i++){
            n1 = n3;
            n3 = n3->next;
        }
        n1->next = n2;
        n2->next = n3;
    }
}
// Remove the item at the end of the list
void pop() {
    if(PythonListHead != NULL){
    struct Node* n1 = PythonListHead;
    struct Node* n2 = NULL;
    if(n1->next == NULL){
        delete_node(n1);
        PythonListHead = NULL;
    }
    else{
    while(n1->next != NULL){
        n2 = n1;
        n1 = n1->next;}
    n2->next = NULL;
    delete_node(n1);
    }
}
}
// Remove all items from the list
void clear() {
    if(len()!=0){ 
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
}    
// Return the number of times x appears in the list.
int count(int x) {
    // your code goes here
    int c = 0;
    if(len()!=0){
    struct Node* temp = PythonListHead;
    while(temp->next != NULL){
        if(temp->data == x){
            c = c + 1; 
        }
        temp = temp->next;}
    if (temp->next == NULL){
        if(temp->data == x){
            c = c + 1; 
        }
    }
    }
    return c;
    }
// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse_h(struct Node* node){
    struct Node* tail = PythonListHead;
    while(tail->next != NULL)
        tail = tail->next;

    if(node->next == NULL){
        return;
    }
    reverse_h(node->next);
    if(node == tail){

    }else{
        (node->next)->next = node;
    }
}
void reverse() {
    if(len()!=0){
    struct Node* tail = PythonListHead;
    while(tail->next != NULL)
        tail = tail->next;

    reverse_h(PythonListHead);
    PythonListHead->next = NULL;
    PythonListHead = tail;
    }
}
// Return the number of elements in the list
// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    if(position>len()-1 || position<0){
        return;
    }
    else{
    struct Node* n1 = PythonListHead;
    if(position==0){
        n1->data = x;
    }
    else{
    struct Node* n1 = PythonListHead;    
    for(int i = 1;i<=position;i++){
        n1 = n1->next;
    }
    n1->data = x;
    }
    }

}
// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    // your code goes here
    if(len()-1<position || position<0){
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
// erase the node at position
// if no such position, do nothing
void erase(int position) {
    struct Node* p = PythonListHead;
    int k=0;
    if(len()==0)
    {
        return;
    }
    else if(position == 0)
    {   
        PythonListHead = PythonListHead->next;
        delete_node(p);
        return;
    }
    while(k<position-1 && p->next!=NULL)
    {
        p = p->next;
        k++; 
    }
    if(k==position-1 && p->next != NULL)
    {
        struct Node* m = p->next;
        p->next = p->next->next;
        m->next = NULL;
        delete_node(m);
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
    PythonListHead1 = NULL;
    int m = 0;
    for(int i = 0 ; i<n ; i++){
        int k = getitem(positions[i]);
        if(k!=-1){
            m+=1;
            if(m==1){
                PythonListHead1 = create_node(k);
            }
            else{
                append2(k);
            }
        }

    }
    return PythonListHead1;
}
// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    if((position+1)!=len() && len() !=0 && (position+1)<len()){
    struct Node* p0 = PythonListHead;
    for(int i = 1;i<(position+1)-1;i++){
            p0 = p0->next;
        }
    if(len() == 2){
        struct Node* p1 = p0->next;
        PythonListHead = p1;
        p0->next = NULL;
        p1->next = p0;
    }
    else{
    if((position+1) == 1){
        struct Node* p1 = p0->next;
        struct Node* p2 = p1->next;
        PythonListHead = p1;
        p0->next = p2;
        p1->next = p0;
    }else{
    struct Node* p1 = p0->next;
    struct Node* p2 = p1->next;
    p0->next = p2;
    p1->next = p2->next;
    p2->next = p1;
}
}
}
}
// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {
    if(len()!=0 && len()!=1){
        struct Node* p1 = PythonListHead, * p2 = PythonListHead->next,* temp;
        int c = 1;
        while(c<len()){
            for(int i = 0; i < len()-c ; i++){
                // printf("For Loop Iteration %d begins\n",i+1);
                if(p1->data>p2->data){
                    // printf("p1:%d\np2:%d\n",p1->data,p2->data);
                    swap(i);
                    temp = p1;
                    p1 = p2;
                    p2 = temp;
                    // printf("p1:%d\np2:%d\n",p1->data,p2->data);
                }
                if(p2->next==NULL){
                    // printf("Breaked\n");
                    break;
                    }
                p1 = p1->next;
                p2 = p2->next;
                
                // printf("p1:%d\np2:%d\n",p1->data,p2->data);
                // printf("For Loop iteration %d:%d\n",c,i);
            }
            // printf("While loop iteration %d\n",c);
            // print_list(PythonListHead);
            // printf("PythonListHead:%d\n",PythonListHead->data);
            c+=1;
            p1 = PythonListHead;
            p2 = PythonListHead->next;
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