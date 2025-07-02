#include <iostream>
using namespace std;
void updateArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        *(arr + i) += 1; // Increment each element by 1
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> *(arr + i);
    }

    updateArray(arr, size);

    cout << "Updated array: ";
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}