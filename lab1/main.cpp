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
    return 0;
}