#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;

node *start = NULL;
node *end = NULL;   // to create LinkList

// Create
node *create(node *start) {
    int data;
    printf("Enter numbers to add to the list (terminate with -1):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        node *p = (node*)malloc(sizeof(node));  // memory allocation of 6 bytes

        if (p == NULL) {
            printf("Not Enough Memory:\n");   // old days to prevent memory leak
            exit(1);
        }
        
        // working inside node:
        // info field  (TO STORE DATA FOR CURRENT NODE)
        p->info = data;     

        // next field  (TO STORE THE ADDRESS OF NEXT NODE)
        p->next = NULL;     

        if (start == NULL) {       // only for 1st node
            start = end = p;
        } else {                   // for other nodes
            end->next = p;
            end = end->next;
        }
    }
    return start;
}

// Display
void display(node *start) {
    node *temp = start;
    while (temp != NULL) {
        // printing the data of current node
        printf("%d  ", temp->info);
        temp = temp->next; // shifting to next node
    }
    printf("\n");
}

// Swap nodes in pairs
node* swap(node* start) {
        // if linklist is empty
    if (start == NULL || start->next == NULL) {
        return start;
    }
    node* cnt = start;
    node* s1 = start->next;
    node* prev = NULL;

    while(cnt != NULL && cnt->next != NULL){
        
        // pointing the node at position of multiple of 3
        node* new_p = cnt->next->next; 

        // pointing the node at position of multiple of 2
        node* snd = cnt->next;

        // swapping the address of the pair nodes
        cnt->next = new_p;
        snd->next = cnt;

        // connecting previous pair to current pair
        if(prev != NULL){
            prev->next = snd;
        }

        // moving to the next pairs
        prev = cnt;
        cnt = new_p;
    }
    return s1;
}

// Swap display
void swap_display(node *start) {
    start = swap(start);
    display(start);
}

int main() {
    int ch = 0;
    do {
        printf("\nLink List Menu\n");
        printf("1. Create\t\t");
        printf("2. Display\t\t");

        printf("3. Swap nodes in pair\t\t");
        printf("4. Display nodes after swapping\t\t");

        printf("5. Exit\t\t\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            start = create(start);
            break;
        case 2:
            printf("Created Link List: \n");
            display(start);
            break;
        case 3:
        printf("Linklist swapped successfully...\n");
            start = swap(start);
            break;
        case 4:
            printf("Link List after Swapping: \n");
            display(start);
            break;
        case 5:
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (ch != 5);
    return 0;
}