#include <iostream>
using namespace std;

void removeElement(int* arr, int& size, int value) {
    int* writePtr = arr;
    int* readPtr = arr;
    int* endPtr = arr + size;
    while (readPtr < endPtr) {
        if (*readPtr != value) {
            *writePtr = *readPtr;
            writePtr++;
        }
        readPtr++;
    }
    size = writePtr - arr;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int value;
    cout << "Enter value to remove: ";
    cin >> value;
    removeElement(arr, n, value);
    cout << "Array after removal: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    delete[] arr;
    return 0;
}