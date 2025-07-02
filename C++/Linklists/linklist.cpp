#include <iostream>
#include <cstdlib>
#include <new>

using namespace std;

struct node {
    int info;      // 4 bytes
    node *next;    // pointer to next node
};

node *start = nullptr;
node *last  = nullptr;

// Create
node* create(node *start) {
    int data;
    node *p = new(nothrow) node;  // allocate a new node
    if (!p) {
        cout << "Not Enough Memory:\n";
        exit(1);
    }
    cout << "Enter a number: ";
    cin  >> data;
    p->info = data;
    p->next = nullptr;

    if (start == nullptr) {       // first node
        start = last = p;
    } else {                      // subsequent nodes
        last->next = p;
        last = last->next;
    }
    return start;
}

// Display
void display(node *start) {
    node *temp = start;
    while (temp->next != nullptr) {
        cout << temp->info << "  ";
        temp = temp->next;
    }
    cout << "\n";
}

// Alternate (print every other node)
void alter(node *start) {
    node *temp = start;
    int count = 1;

    while (temp->next != nullptr) {
        if (count % 2 != 0) {
            cout << temp->info << "  ";
        }
        temp = temp->next;
        count++;
    }
    cout << "\n";
}

// Insert at last
node* insert_last(node *start) {
    int num;
    cout << "Enter a number to be inserted at last: ";
    cin  >> num;

    node *p = new node;
    p->info = num;
    p->next = nullptr;

    node *temp = start;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = p;

    return start;
}

// Insert at beginning
node* insert_begin(node *start) {
    int num;
    cout << "Enter a number to be inserted at beginning: ";
    cin  >> num;

    node *p = new node;
    p->info = num;
    p->next = start;
    start = p;

    return start;
}

// Insert before a given node
node* insert_before(node *start) {
    node *prev, *temp = start;
    int val, num;
    cout << "Enter the value to insert before the node: ";
    cin  >> val;
    cout << "Now, enter a number to be inserted: ";
    cin  >> num;

    node *p = new node;
    p->info = num;
    p->next = start;

    while (temp->info != val) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = p;
    p->next    = temp;

    return start;
}

// Insert after a given node
node* insert_after(node *start) {
    node *far, *temp = start;
    int val, num;
    cout << "Enter the value to insert after the node: ";
    cin  >> val;
    cout << "Now, enter a number to be inserted: ";
    cin  >> num;

    node *p = new node;
    p->info = num;
    p->next = start;

    while (temp->info != val) {
        far  = temp;
        temp = temp->next;
    }
    far        = temp->next;
    temp->next = p;
    p->next    = far;

    return start;
}

// Delete at beginning
node* delete_begin(node *start) {
    node *p = start;
    start = p->next;
    delete p;
    return start;
}

// Delete at last
node* delete_last(node *start) {
    node *temp = start, *prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
    return start;
}

// Delete before a given node
node* delete_before(node *start) {
    node *prev, *temp = start;
    int num;
    cout << "Enter the data of the node to delete before: ";
    cin  >> num;

    while (temp->info != num) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
    return start;
}

// Delete after a given node
node* delete_after(node *start) {
    node *prev = start, *temp = start;
    int num;
    cout << "Enter the data of the node to delete after: ";
    cin  >> num;

    while (prev->info != num) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
    return start;
}

// Delete entire list
node* delete_list(node *start) {
    node *temp;
    while (start != nullptr) {
        temp  = start;
        start = start->next;
        delete temp;
    }
    return start;
}

int main() {
    int ch = 0;
    do {
        cout << "\nLink List Menu\n"
             << "1.  Create\n"
             << "2.  Display\n"
             << "3.  Insert At Last\n"
             << "4.  Insert At Beginning\n"
             << "5.  Insert Before a given node\n"
             << "6.  Insert After a given node\n"
             << "7.  Delete At Beginning\n"
             << "8.  Delete At Last\n"
             << "9.  Delete at position\n"
             << "10. Delete after the given node\n"
             << "11. Delete Link List\n"
             << "12. Sorting The Linked List (Alternate print)\n"
             << "13. Exit\n"
             << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:  start = create(start);              break;
            case 2:  cout << "Created Linked List:\n"; display(start); break;
            case 3:  start = insert_last(start);         break;
            case 4:  start = insert_begin(start);        break;
            case 5:  start = insert_before(start);       break;
            case 6:  start = insert_after(start);        break;
            case 7:  start = delete_begin(start);        break;
            case 8:  start = delete_last(start);         break;
            case 9:  start = delete_before(start);       break;
            case 10: start = delete_after(start);        break;
            case 11: cout << "Linked List has been Deleted...\n";
                     start = delete_list(start);         break;
            case 12: cout << "Alternate Linked List:\n"; alter(start);   break;
            case 13: cout << "Exiting...\n"; exit(0);
            default: cout << "Invalid Choice\n";
        }
    } while (ch != 13);

    return 0;
}
