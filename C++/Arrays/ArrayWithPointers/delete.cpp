#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);
    }

    cout << "Array elements are:\n";
    for (int i = 0; i < n; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    int pos;
    cout << "Enter position to delete (0-based index): ";
    cin >> pos;
    if (pos >= 0 && pos < n) {
        for (int i = pos; i < n - 1; ++i) {
            *(arr + i) = *(arr + i + 1);
        }
        --n;
        cout << "Array after deletion:\n";
        for (int i = 0; i < n; ++i) {
            cout << *(arr + i) << " ";
        }
        cout << endl;
    } else {
        cout << "Invalid position!\n";
    }

    delete[] arr;
    return 0;
}