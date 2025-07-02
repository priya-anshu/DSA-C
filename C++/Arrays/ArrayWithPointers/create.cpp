#include <iostream>
using namespace std;

void removeElement(int *arr, int &size, int element) {
    int *ptr = arr;
    int i = 0;
    while (i < size) {
        if (*(ptr + i) == element) {
            // Shift elements to the left using pointers
            for (int j = i; j < size - 1; j++) {
                *(ptr + j) = *(ptr + j + 1);
            }
            size--;
        } else {
            i++;
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> *(arr + i); // Input using pointer arithmetic
    }

    int element;
    cout << "Enter the element to remove: ";
    cin >> element;

    removeElement(arr, size, element);

    cout << "Array after removal: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}