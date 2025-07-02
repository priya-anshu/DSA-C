#include <iostream>
using namespace std;

int main() {
    // Create an array of integers with 5 elements
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];

    for(int i = 0; i < size; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> arr[i]; // Input elements into the array
    }
    // Print the elements of the array
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}