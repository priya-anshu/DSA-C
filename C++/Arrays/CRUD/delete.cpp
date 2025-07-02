#include <iostream>
using namespace std;

void removeElement(int arr[], int &size, int element) {
    int i = 0;
    while (i < size) {
        if (arr[i] == element) {
            // Shift elements to the left
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--; // Decrease the size of the array
        } else {
            i++; // Only increment if no deletion occurred
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> arr[i]; // Input elements into the array
    }

    int element;
    cout << "Enter the element to remove: ";
    cin >> element;

    removeElement(arr, size, element);

    cout << "Array after removal: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}