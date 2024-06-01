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
        node *p = (node*)malloc(sizeof(node));  // memory allocation

        if (p == NULL) {
            printf("Not Enough Memory:\n");   
            exit(1);
        }
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
        printf("%d  ", temp->info); // printing the data of current node
        temp = temp->next; // shifting to next node
    }
    printf("\n");
}

// insert_after
node *insert_after(node *start){
    node *far, *temp;
      int num,val;
    printf("Enter the value to insert after the node:\n");
    scanf("%d",&val);
    printf("Now, Enter a number to be inserted: \n");
    scanf("%d",&num);
    node *p =(node*)malloc(sizeof(node));
    p->info = num;
    p->next = start;
    temp = start;
    
    while (temp->info != val){
         far = temp;
        temp = temp->next;
    }
    far = temp->next;
    temp->next = p;
    p->next = far;
    return start;
}

int main() {
    int ch = 0;
    do {
        printf("\nLink List Menu\n");
        printf("1. Create\t\t\t");
        printf("2. Display\t\t\t\n");
        printf("3. Insert after Nth node\t");
        printf("4. Exit\n");
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
            start = insert_after(start);
            break;
        
        case 4:
            break;

        default:
            printf("Invalid Choice\n");
        }
    } while (ch != 4);
    return 0;
}