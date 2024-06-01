#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;

node *start = NULL;
node *end = NULL;   // to create LinkList
node *Q_start = NULL, *Q_end = NULL; // to create Q list
node *R_start = NULL, *R_end = NULL; // to create R list

// Create
node *create(node *start) {
    int data;
    printf("Enter numbers to add to the list (terminate with -1):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        node *p = (node*)malloc(sizeof(node));  // memory allocation

        if (p == NULL) {
            printf("Not Enough Memory:\n");   
            exit(1);
        }
        
        p->info = data;     // info field  (TO STORE DATA FOR CURRENT NODE)
        p->next = NULL;     // next field  (TO STORE THE ADDRESS OF NEXT NODE)

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
        printf("%d  ", temp->info); // printing the data of current node
        temp = temp->next; // shifting to next node
    }
    printf("\n");
}

// Split function
void split(node *start) {
    node *temp = start;
    int position = 1;

    while (temp != NULL) {
        node *newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL) {
            printf("Not Enough Memory:\n");
            exit(1);
        }
        newNode->info = temp->info;
        newNode->next = NULL;

        if (position % 2 != 0) {  // Odd position
            if (Q_start == NULL) {
                Q_start = Q_end = newNode;
            } else {
                Q_end->next = newNode;
                Q_end = Q_end->next;
            }
        } else {  // Even position
            if (R_start == NULL) {
                R_start = R_end = newNode;
            } else {
                R_end->next = newNode;
                R_end = R_end->next;
            }
        }

        temp = temp->next;
        position++;
    }
}

int main() {
    int ch = 0;
    do {
        printf("\nLink List Menu\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Split\n");
        printf("4. Display Q and R\n");
        printf("5. Exit\n");
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
            split(start);
            break;

        case 4:
            printf("Linked List Q (odd positions): \n");
            display(Q_start);
            printf("Linked List R (even positions): \n");
            display(R_start);
            break;

        case 5:
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (ch != 5);
    return 0;
}
