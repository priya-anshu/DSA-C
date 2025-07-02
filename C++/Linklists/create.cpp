#include <iostream>
using namespace std;
// This code defines a simple linked list structure in C++ with a Node class and a LinkedList class.
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};
// The LinkedList class manages the linked list, including head and tail pointers.
// It initializes the head and tail pointers to NULL in the constructor.
class LinkedList {
    //by default, the head and tail pointers are private members of the LinkedList class.
    Node* head;
    Node* tail;

    public:
    // Constructor to initialize the linked list with head and tail as NULL
    // This ensures that the linked list starts empty.
    LinkedList(){
        head = tail = NULL;
    }
    void push_front(int value) {
        Node* newNode = new Node(value); //dynamically allocate a new node with the given value
        // Check if the list is empty
        if (head == NULL) {
            head = tail = newNode; // If the list is empty, set both head and tail to the new node
        } else {
            newNode->next = head; // Link the new node to the current head
            head = newNode;       // Update head to point to the new node
        }
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> "; // Print the data of each node
            temp = temp->next;            // Move to the next node
        }
        cout << "NULL" << endl; 
    }
};

int main(){
    LinkedList list; 
    list.push_front(10); 
    list.push_front(20); 
    list.push_front(30); 

    list.display();
    return 0;
}