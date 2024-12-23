#pragma once


#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
private:
    T* arr;
    size_t size;

public:
    Array(size_t n);
    Array(size_t n, bool random);
    Array(size_t n, T min, T max);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    ~Array();

    void display() const;
    void fillWithRandomValues();
    void resize(size_t newSize);
    void sort();
    T min() const;
    T max() const;

};


