#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int con;
    int pow;
    struct node *next;
} node;

node *s1 = NULL;
node *s2 = NULL;
node *s3 = NULL;

// Create a polynomial
node *create() {
    int coff, power;
    node *start = NULL, *end = NULL;
    printf("Enter coefficient and power (-1 to end):\n");
    while (1) {

        printf("Coefficient: ");
        scanf("%d", &coff);

        if (coff == -1) 
        break;

        printf("Power: ");
        scanf("%d", &power);

        node *p = (node *)malloc(sizeof(node));
        p->con = coff;
        p->pow = power;
        p->next = NULL;

        if (start == NULL) {
            start = end = p;
        } 
        else {
            end->next = p;
            end = end->next;
        }
    }
    return start;
}

// Display a polynomial
void display(node *start) {

    node *temp = start;
    while (temp != NULL) {
        
        printf("%dx^%d ", temp->con, temp->pow);
        if (temp->next != NULL) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Add two polynomials
node *add(node *s1, node *s2) {
    node *p1 = s1, *p2 = s2;
    node *s3 = NULL, *end = NULL;

    while (p1 != NULL && p2 != NULL) {
        node *p = (node *)malloc(sizeof(node));

        if (p1->pow == p2->pow) {

            p->con = p1->con + p2->con;
            p->pow = p1->pow;

            p1 = p1->next;
            p2 = p2->next;
        } 
        else if (p1->pow > p2->pow) {

            p->con = p1->con;
            p->pow = p1->pow;

            p1 = p1->next;
        } 
        else {
            p->con = p2->con;
            p->pow = p2->pow;
            p2 = p2->next;
        }
        p->next = NULL;

        if (s3 == NULL) {
            s3 = end = p;
        } 
        else {
            end->next = p;
            end = end->next;
        }
    }

    while (p1 != NULL) {
        node *p = (node *)malloc(sizeof(node));

        p->con = p1->con;
        p->pow = p1->pow;
        p->next = NULL;

        if (s3 == NULL) {
            s3 = end = p;
        } 
        else {
            end->next = p;
            end = end->next;
        }
        p1 = p1->next;
    }

    while (p2 != NULL) {
        node *p = (node *)malloc(sizeof(node));

        p->con = p2->con;
        p->pow = p2->pow;
        p->next = NULL;

        if (s3 == NULL) {
            s3 = end = p;
        } 
        else {
            end->next = p;
            end = end->next;
        }
        p2 = p2->next;
    }

    return s3;
}

int main() {
    int ch = 0;
    do {
        printf("\nPolynomial Menu\n");
        printf("1. Create 1st Polynomial\n");
        printf("2. Display 1st Polynomial\n");
        printf("3. Create 2nd Polynomial\n");
        printf("4. Display 2nd Polynomial\n");
        printf("5. Add Polynomials\n");
        printf("6. Display Result Polynomial\n");
        printf("7. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            s1 = create();
            break;
        case 2:
            printf("1st Polynomial: \n");
            display(s1);
            break;
        case 3:
            s2 = create();
            break;
        case 4:
            printf("2nd Polynomial: \n");
            display(s2);
            break;
        case 5:
            s3 = add(s1, s2);
            printf("Polynomials added successfully.\n");
            break;
        case 6:
            printf("Resultant Polynomial: \n");
            display(s3);
            break;
        case 7:
            printf("Exiting... \n");
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    } while (ch != 7);
    return 0;
}
