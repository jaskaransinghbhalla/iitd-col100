#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len();
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
    
    if (PythonListHead == NULL)
    {
        PythonListHead = new;
        return;
    }
    
    struct Node* cur = PythonListHead;
    while(cur) {
        if (cur->next == NULL)
        {
            cur->next = new;
            break;
        }
        
        cur = cur->next;
    }
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    
    struct Node* new = create_node(x);
    struct Node* cur = PythonListHead;
    struct Node* pre = PythonListHead;

    if (position == 0)
    {
        new->next = PythonListHead;
        PythonListHead = new;
        return;
    }
    else if(position == len()){
        while(cur->next!=NULL){
            pre = pre->next;
            cur = cur->next;
        }
        cur->next = new;
        return;
    }
    else{
    for (int i = 0; i < position && cur != NULL; i++)
    {
        pre = cur;
        cur = cur->next;
    }
    
    if (cur == NULL)
    {
        return;
    }
    
    new->next = cur;
    pre->next = new;
    return;
}
}


// Remove the item at the end of the list
void pop() {
    
    struct Node* cur = PythonListHead;
    struct Node* pre = PythonListHead;

    while (cur)
    {
        if (cur->next == NULL)
        {
            delete_node(cur);
            
            if (cur == PythonListHead)
            {
                PythonListHead = NULL;
            }
            
            pre->next = NULL;
            return;
        }
        
        pre = cur;
        cur = cur->next;
    }
}


// Remove all items from the list
void clear() {
    
    struct Node* upcomng = PythonListHead;
    struct Node* current = PythonListHead;

    while (current != NULL)
    {
       upcomng = current->next;
       delete_node(current);
       current = upcomng;
    }

    PythonListHead = NULL;

    return;
}


// Return the number of times x appears in the list.
int count(int x) {
    
    struct Node* cur = PythonListHead;
    int count = 0;
    
    while(cur) {
        if (cur->data == x)
        {
            count++;
        }
        
        cur = cur->next;
    }
    
    return count;
}


// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    
    struct Node* current = PythonListHead;
    struct Node* reverse = NULL;
    struct Node* upcoming;

    while (current != NULL)
    {
        upcoming = current->next;
        current->next = reverse;
        reverse = current;
        current = upcoming;
    }

    PythonListHead = reverse;
}


// Return the number of elements in the list

int len() {
    
    struct Node* cur = PythonListHead;
    int length = 0;

    while(cur) {
        
        length++;
        
        if (cur->next == NULL)
        {
            break;
        }
        
        cur = cur->next;
    }
    
    return length;
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    struct Node* cur = PythonListHead;

    for (int i = 0; i <= position & cur != NULL; i++)
    {
        if (i == position)
        {
            cur->data = x;
            return;
        }
        
        cur = cur->next;
    }
    return;
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem();
int getitem(int position) {
    int item = -1;
    struct Node* cur = PythonListHead;

    for (int i = 0; i <= position & cur != NULL; i++)
    {
        if (i == position)
        {
            item = cur->data;
            return item;
        }
        
        cur = cur->next;
    }

    return -1;
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    struct Node* cur = PythonListHead;
    struct Node* pre = PythonListHead;

    for (int i = 0; i <= position & cur != NULL; i++)
    {
        if (i == position)
        {
            if (cur == PythonListHead)
            {
                PythonListHead = cur->next;
            }

            pre->next = cur->next;
            
            delete_node(cur);
            return;
        }
        
        pre = cur;
        cur = cur->next;
    }
    return;
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
    
    struct Node* PythonListHeadNew = NULL;

    for (int i = 0; i < n; i++)
    {
        int index = positions[i];
        int item = getitem(index);
        
        if (item == -1)
        {
            continue;
        }
         
        // Appending in the new List
        struct Node* new = create_node(item);
    
        if (PythonListHeadNew == NULL)
        {
            PythonListHeadNew = new;
            continue;
        }
        
        else
        {
            struct Node* fur = PythonListHeadNew;
            while(fur) 
            {
                if (fur->next == NULL)
                {
                    fur->next = new;
                    break;
                }
                        
                fur = fur->next;
            }
        }
    }

    return PythonListHeadNew;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    
    struct Node* post = PythonListHead;
    struct Node* pre = PythonListHead;
    struct Node* one;
    struct Node* four;
    ;
    if (position<0 || position>=len()-1){
        return;
    }
    else if(position == 0)
    {
        one = PythonListHead;
        four = PythonListHead->next->next;
        PythonListHead = PythonListHead->next;
        PythonListHead->next = one;
        one->next = four;
        
        return;
    }
    else{
    for (int i = 0; i < position & post != NULL; i++)
    {
        one = pre;
	    pre = pre->next;
        post = pre->next;
    }
    
    if (post == NULL)
    {
        return;
    }

    four = post->next;

    // All pointers assigned respective values
    one->next = post;
    post->next = pre;
    pre->next = four;
    
    return;
}
}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {
    
    struct Node* cur = PythonListHead;
    int n = len();
    int i, j;
    
    // Iterating n-1 times over the list
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (getitem(j) > getitem(j + 1))
                swap(j);
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