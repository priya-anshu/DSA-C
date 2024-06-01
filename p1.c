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
node *swap(node* start) {
    node *current = start;
    while (current != NULL && current->next != NULL) {
        int temp = current->info;
        current->info = current->next->info;
        current->next->info = temp;
        current = current->next->next;
    }
    return start;
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
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Swap nodes in pair\n");
        printf("4. Display nodes after swapping\n");
        printf("5. Exit\n");
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
            start = swap(start);
            break;
        case 4:
            printf("Link List after Swapping: \n");
            swap_display(start);
            break;
        case 5:
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (ch != 5);
    return 0;
}
