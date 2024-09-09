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
void retain_and_delete(node *start, int M, int N) {
    node *current = start;
    node *temp;

    while (current != NULL) {
        // Retain M nodes
        for (int i = 1; i < M && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL) return;

        // Delete next N nodes
        temp = current->next;
        for (int i = 1; i <= N && temp != NULL; i++) {
            node *next = temp->next;
            free(temp);
            temp = next;
        }
        // Connect the retained nodes to the rest of the list
        current->next = temp;

        
        if (temp != NULL) {
        temp->prev->next = current;
        current = temp;
        break;
        }
        current = temp;
    }
}

int main() {
    int ch = 0;
    do {
        printf("\nLink List Menu\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Retain and Delete\n");
        printf("4. Exit\n\n");
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
            retain_and_delete(start, M, N);
            printf("Link List after retaining %d nodes and deleting next %d nodes:\n", M, N);
            display(start);
            break;
        }

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    } while (ch != 4);
    return 0;
}