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
    // Конструктор
    DynamicArray(int n) {
        size = n;
        data = new int[size];
    }

    // Деструктор
    ~DynamicArray() {
        delete[] data;
    }

    // Вывод всех элементов
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Сеттер
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        if (value < -100 || value > 100) {
            throw invalid_argument("Value must be from -100 to 100");
        }

        data[index] = value;
    }

    // Геттер
    int get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        return data[index];
    }

    // Конструктор копирования
    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Добавление элемента в конец
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

    // Сложение массивов
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

    // Вычитание массивов
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

    // Получение размера
    int getSize() const {
        return size;
    }
};

#endif