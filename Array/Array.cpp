#include"Array.h"
#include<iostream>
#include<cstring>
#include<algorithm>

template <typename T>
Array<T>::Array(size_t n) : size(n) {
    arr = new T[size]();
}

template <typename T>
Array<T>::Array(size_t n, bool random) : size(n) {
    arr = new T[size];
    if (random) {
        fillWithRandomValues();
    }
}

template <typename T>
Array<T>::Array(size_t n, T min, T max) : size(n) {
    arr = new T[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = min + static_cast<T>(rand() % (max - min + 1));
    }
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size) {
    arr = new T[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = other.arr[i];
    }
}

// ����������� �������� 

template <typename T>
Array<T>::Array(Array&& other) noexcept : arr(other.arr), size(other.size) {
    other.arr = nullptr;
    other.size = 0;
}

// �������� =

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] arr;
        size = other.size;
        arr = new T[size];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

// �������� �������� ��������� 

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] arr;
        size = other.size;
        arr = other.arr;
        other.size = 0;
        other.arr = nullptr;
    }
    return *this;
}


template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
void Array<T>::display() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Array<T>::fillWithRandomValues() {
    for (size_t i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}

template <typename T>
void Array<T>::resize(size_t newSize) {
    T* newArr = new T[newSize];
    size_t copySize = (newSize < size) ? newSize : size;
    for (size_t i = 0; i < copySize; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size = newSize;
}

template <typename T>
void Array<T>::sort() {
    std::sort(arr, arr + size);
}

template <typename T>
T Array<T>::min() const {
    if (size == 0) {
        std::cout << "Array is empty" << std::endl;
        return T();
    }

    T minValue = arr[0];
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

template <typename T>
T Array<T>::max() const {
    if (size == 0) {
        std::cout << "Array is empty" << std::endl;
        return T();
    }

    T Array<T>::max() const {
        if (size == 0) {
            std::cout << "Array is empty" << std::endl;
            return 0;
        }
        T maxValue = arr[0];
        for (size_t i = 0; i < size; ++i) {
            if (arr[i] > maxValue) {
                maxValue = arr[i];
            }
        }
        return maxValue;
    }
}

#include"Array.h"


    //// �������� �������� +
    //Array Array::operator+(const Array & other) const {
    //    Array result(size + other.size);
    //    for (size_t i = 0; i < size; ++i) {
    //        result.arr[i] = arr[i];
    //    }
    //    for (size_t i = 0; i < other.size; ++i) {
    //        result.arr[size + i] = other.arr[i];
    //    }
    //    return result;
    //}

    //// �������� +=
    //Array& Array::operator+=(const Array & other) {
    //    size_t newSize = size + other.size;
    //    int* newArr = new int[newSize];
    //    for (size_t i = 0; i < size; ++i) {
    //        newArr[i] = arr[i];
    //    }
    //    for (size_t i = 0; i < other.size; ++i) {
    //        newArr[size + i] = other.arr[i];
    //    }
    //    delete[] arr;
    //    arr = newArr;
    //    size = newSize;
    //    return *this;
    //}

    //// �������� []
    //int& Array::operator[](size_t index) {
    //    if (index >= size) {
    //        throw std::out_of_range("Index out of bounds");
    //    }
    //    return arr[index];
    //}

    //// �������� <<
    //std::ostream& operator<<(std::ostream & os, const Array & array) {
    //    for (size_t i = 0; i < array.size; ++i) {
    //        os << array.arr[i] << " ";
    //    }
    //    return os;
    //}

    //// �������� ==
    //bool Array::operator==(const Array & other) const {
    //    if (size != other.size) return false;
    //    for (size_t i = 0; i < size; ++i) {
    //        if (arr[i] != other.arr[i]) return false;
    //    }
    //    return true;
    //}

    //// �������� !=
    //bool Array::operator!=(const Array & other) const {
    //    return !(*this == other);
    //}

    //// �������� >
    //bool Array::operator>(const Array & other) const {
    //    return size > other.size;
    //}

    //// �������� <
    //bool Array::operator<(const Array & other) const {
    //    return size < other.size;
    //}