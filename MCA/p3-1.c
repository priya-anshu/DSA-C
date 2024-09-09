#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev; // 2 BYTES
    int info;          // 4 BYTES
    struct node *next; // 2 BYTES
} node;                // total size 8 BYTES

node *start = NULL;
node *end = NULL; // to create LinkList

// Create
node *create(node *start) {
    int data;
    printf("Enter numbers to add to the list (terminate with -1):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        node *p = (node *)malloc(sizeof(node)); // memory allocation

        if (p == NULL) {
            printf("Not Enough Memory.\n");
            exit(1);
        }

        p->info = data;
        p->next = NULL;
        p->prev = NULL;

        if (start == NULL) {
            end = start = p;
        } else {
            end->next = p;
            p->prev = end;
            end = end->next;
        }
    }
    return start;
}

// Display
void display(node *start) {
    node *temp = start;

    while (temp != NULL) {
        printf("%d  ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

// Retain M nodes and delete next N nodes
node* retain(node*start,int m,int n){
    node*m1 = start;
    node* n1 = NULL;

    while(n1 != NULL){
    for(int i=1; i<=m; i++){
        m1 = m1->next;
    }

    n1 = m1->next;
    printf("%d",n1->info);
    
    // Deletion upto Nth position
    node*temp = n1->next;
    for(int i=1; i<=n;i++){
        node* del = n1->next;
        free(temp);
        temp = del;
    }
    n1->next = temp;

    if(temp != NULL)
    temp ->prev = n1;
    n1 = temp;
    }
}

int main() {
    int ch = 0;
    do {
        printf("\nLink List Menu\n");
        printf("1. Create\t");
        printf("2. Display\t");
        printf("3. Retain and Delete\n");
        printf("12. Exit\n\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            start = create(start);
            break;

        case 2:
            printf("Created Link List: \n");
            display(start);
            break;

        case 3: {
            int M, N;
            printf("Enter the number of nodes to retain (M): ");
            scanf("%d", &M);
            
            printf("Enter the number of nodes to delete (N): ");
            scanf("%d", &N);

            retain(start, M, N);
            printf("Link List after retaining %d nodes and deleting next %d nodes:\n", M, N);
            display(start);
            break;
        }

        case 12:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    } while (ch != 12);
    return 0;
}
