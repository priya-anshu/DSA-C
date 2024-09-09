#include <stdio.h>
#include <stdlib.h>

// Define the structure of the tree node
typedef struct Node {
    int info;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->info = data;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return create(data);
    }
    if (data < root->info) {
        root->left = insert(root->left, data);
    } else if (data > root->info) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to count total leaf nodes
int leafNode(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return leafNode(root->left) + leafNode(root->right);
}

// Function to count nodes with only left child
int leftChild(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left != NULL && root->right == NULL) {
        return 1 + leftChild(root->left) + leftChild(root->right);
    }
    return leftChild(root->left) + leftChild(root->right);
}

// Function to count nodes with only right child
int rightChild(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right != NULL) {
        return 1 + rightChild(root->left) + rightChild(root->right);
    }
    return rightChild(root->left) + rightChild(root->right);
}

// Function to count nodes with both left and right children
int bothChild(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left != NULL && root->right != NULL) {
        return 1 + bothChild(root->left) + bothChild(root->right);
    }
    return bothChild(root->left) + bothChild(root->right);
}

// Function to find the minimum value in the BST
int findMin(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->info;
}

// Function to find the maximum value in the BST
int findMax(Node* root) {
    Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current->info;
}

// Function for preOrder traversal
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for postOrder traversal
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->info);
    }
}

// Function for inOrder traversal
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->info);
        inOrder(root->right);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert Node\n");
    printf("2. Count Total Leaf Nodes\n");
    printf("3. Count Nodes with Only Left Child\n");
    printf("4. Count Nodes with Only Right Child\n");
    printf("5. Count Nodes with Both Children\n");
    printf("6. Find Minimum Value\n");
    printf("7. Find Maximum Value\n");
    printf("8. PreOrder Traversal\n");
    printf("9. PostOrder Traversal\n");
    printf("10. InOrder Traversal\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Total leaf nodes: %d\n", leafNode(root));
                break;
            case 3:
                printf("Nodes with only left child: %d\n", leftChild(root));
                break;
            case 4:
                printf("Nodes with only right child: %d\n", rightChild(root));
                break;
            case 5:
                printf("Nodes with both children: %d\n", bothChild(root));
                break;
            case 6:
                if (root) {
                    printf("Minimum value in the BST: %d\n", findMin(root));
                } else {
                    printf("The tree is empty.\n");
                }
                break;
            case 7:
                if (root) {
                    printf("Maximum value in the BST: %d\n", findMax(root));
                } else {
                    printf("The tree is empty.\n");
                }
                break;
            case 8:
                printf("PreOrder Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 9:
                printf("PostOrder Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 10:
                printf("InOrder Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}