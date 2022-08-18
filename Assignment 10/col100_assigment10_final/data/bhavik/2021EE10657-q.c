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
    struct Node* new = create_node(x);
        if(PythonListHead == NULL)
        {
            PythonListHead = new;
            return;
        }

        struct Node* cur = PythonListHead;
        while(cur)
        {
            if(cur->next == NULL)
            {
                cur->next = new;
                break;
            }
            cur = cur->next;
        }
}


// Return the number of elements in the list
int len() {
    // your code goes here
    struct Node* p = PythonListHead;
    int l=0;
    while(p != NULL)
    {
        l=l+1;
        p = p->next;
    }
    return l;
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    int l=len();
    if(position>=0 && position<l)
    {    
        struct Node* p = PythonListHead;
        struct Node* new = create_node(x);
            if(PythonListHead == NULL)
            {
                PythonListHead = new;
            }
            else
            {
                int i=0;
                struct Node* temp,*newnode,*nextnode;
                temp=p;
                if(position == 0)
                {
                    newnode = create_node(x);
                    newnode->next = temp;
                    PythonListHead=newnode;
                }
                else
                {    
                    newnode = create_node(x);
                    while(i<position-1)
                    {
                        temp=temp->next;

                        i++;
                    }
                    nextnode=temp->next;
                    temp->next=newnode;
                    newnode->next=nextnode;
                    p=temp;
                }

            }
    }
}


// Remove the item at the end of the list
void pop() {
    struct Node* p = PythonListHead;
    if(p != NULL)    
    {
        struct Node* q = PythonListHead->next;   
        if (q != NULL)
        {    
            while(q->next != NULL)
            {
                p=p->next;
                q=q->next;
            }
            p->next = NULL;
            free(q);
        }
        else
        {
            PythonListHead = NULL;
            free(q);
        }
    }
}


// Remove all items from the list
void clear() {
    int l=len();
    for(int i=0;i<l;++i)
        pop();
}


// Return the number of times x appears in the list.
int count(int x) {
    // your code goes here
    struct Node* cur = PythonListHead;
        int count = 0;
        while(cur)
        {
            if(cur->data==x)
            {
                count++;
            }
            cur=cur->next;
        }
        return count;
}


// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* p = PythonListHead;
    if(p!=NULL)
    {
        struct Node* temp,*prevnode,*nextnode;
        temp=p;
        prevnode=p;
        nextnode=p;
          
        while(nextnode->next != NULL)
        {
           nextnode=nextnode->next;
            if(temp==p)
                temp->next=NULL;
            else
                temp->next=prevnode;
            
            prevnode=temp;
            temp=nextnode; 
        }
    
        temp->next=prevnode;
        PythonListHead = temp;
    }


}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    int l=len();
    struct Node* p = PythonListHead;
    if(position>=0 && position<l)
    {
        for(int i=0;i<position;++i)
        {
            p = p->next;
        }
        p->data=x;
    }
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    // your code goes here
    struct Node* p = PythonListHead;
    int l=len();
    if(position<l && position>=0)
    {
        for(int i=0;i<position;i++)
        {
            p = p->next;
        }
        int x = p->data;
        return x;
    }
    return -1;
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    int l=len();
    if(position<l && position>=0)
    {
        
        if(position == 0)
        {
            struct Node* p = PythonListHead;
            PythonListHead = p->next;
            free(p);
        }
        else if(position==l-1)
        {
            pop();
        }
        else
        {
            struct Node* p = PythonListHead;
            struct Node* r = PythonListHead;
            struct Node* q = PythonListHead->next;
            for(int i=0;i<position-1;i++)
            {
                p = p->next;
                q = q->next;
            }
            p->next = q->next;
            free(q);
            PythonListHead=r;
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
    // your code goes here
    return NULL;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    struct Node* p = PythonListHead;
    int l=len();
    if (((l != 1) || (l !=0)) && (position<l-1))
    {
        struct Node* q = PythonListHead->next;
        if(position == 0)
        { 
            p->next=q->next;
            q->next = p;
            PythonListHead = q;
        }
        else if(position == l-2)
        {
            
            for(int i=0;i<position-1;i++)
            {
                p = p->next;
                q = q->next;
            }
            struct Node* r = q->next;
            p->next = q->next;
            q->next = NULL;
            r->next = q;
        }
        else
        {
            struct Node* r = q->next;
            for(int i=0;i<position-1;i++)
            {
                p = p->next;
                q = q->next;
                r = r->next;
            }
            p->next = q->next;
            q->next = r->next;
            r->next = q;
        }
    }
}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {
    struct Node*p = PythonListHead;
    struct Node* temp,*nextnode,*temp1;
    temp=p;

    while(temp->next!=NULL)
    {
        temp1=p;
        nextnode=p;
        while(nextnode->next!=NULL)
        {
            temp1=nextnode;
            nextnode=nextnode->next;
            if(nextnode->data<temp1->data)
            {
                int k=nextnode->data;
                nextnode->data=temp1->data;
                temp1->data=k;
            }
            
        }
        temp=temp->next;
    }
    
    p=temp;

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