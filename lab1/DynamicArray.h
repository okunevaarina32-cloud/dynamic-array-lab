#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <stdexcept>

using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int n) {
        size = n;
        data = new int[size];
    }
    ~DynamicArray() {
        delete[] data;
    }
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        if (value < -100 || value > 100) {
            throw invalid_argument("Value must be from -100 to 100");
        }
        data[index] = value;
    }
    int get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    void pushBack(int value) {
        if (value < -100 || value > 100) {
            throw invalid_argument("Value must be from -100 to 100");
        }
        int* newData = new int[size + 1];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        newData[size] = value;
        delete[] data;
        data = newData;
        size++;
    }
    DynamicArray operator+(const DynamicArray& other) const {
        DynamicArray result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i];
            if (i < other.size) {
                result.data[i] += other.data[i];
            }
        }
        return result;
    }
    DynamicArray operator-(const DynamicArray& other) const {
        DynamicArray result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i];
            if (i < other.size) {
                result.data[i] -= other.data[i];
            }
        }
        return result;
    }
    int getSize() const {
        return size;
    }
};
#endif