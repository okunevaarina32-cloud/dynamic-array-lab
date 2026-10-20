#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main() {

    cout << "Task 1" << endl;
    DynamicArray a(3);
    a.set(0, 10);
    a.set(1, -20);
    a.set(2, 30);
    cout << "Array a: ";
    a.print();
    cout << "Element at index 1: ";
    cout << a.get(1) << endl;

    cout << "\nTask 2" << endl;
    DynamicArray b(a);
    cout << "Copied array b: ";
    b.print();

    cout << "\nTask 3" << endl;
    a.pushBack(40);
    cout << "Array a after pushBack: ";
    a.print();
    cout << "New size: ";
    cout << a.getSize() << endl;

    cout << "\nTask 4" << endl;
    DynamicArray c(2);
    c.set(0, 5);
    c.set(1, 7);
    DynamicArray sum = a + c;
    DynamicArray difference = a - c;

    cout << "Sum: ";
    sum.print();

    cout << "Difference: ";
    difference.print();
        cout << "\nTask 5: Exceptions" << endl;

    try {
        cout << a.get(100) << endl;
    }
    catch (const out_of_range& e) {
        cout << "out_of_range: " << e.what() << endl;
    }

    try {
        a.set(0, 200);
    }
    catch (const invalid_argument& e) {
        cout << "invalid_argument: " << e.what() << endl;
    }

    try {
        int* memory = new int[1000000000000ULL];
        delete[] memory;
    }
    catch (const bad_alloc& e) {
        cout << "bad_alloc: " << e.what() << endl;
    }
    return 0;
}