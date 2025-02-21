#include <iostream>
#include <cassert>
#include <initializer_list>
#include <algorithm> // Include this for std::copy

template<typename T, size_t N>
class array {
private:
    T data[N];
public:
    // Default constructor
    array() {}

    // Constructor with initializer list
    array(std::initializer_list<T> list) {
        std::copy(list.begin(), list.end(), data);
    }

    // Access and modify elements
    T& operator[](size_t index) {
        return data[index];
    }

    // Constant access for read-only operations
    const T& operator[](size_t index) const {
        return data[index];
    }

    // Size of the array
    constexpr size_t size() const {
        return N;
    }

    // Overload + operator to add two arrays
    array<T, N> operator+(const array<T, N>& other) const {
        array<T, N> result;
        for (size_t i = 0; i < N; i++) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    // Overload - operator to subtract two arrays
    array<T, N> operator-(const array<T, N>& other) const {
        array<T, N> result;
        for (size_t i = 0; i < N; i++) {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    // Overload == operator to compare two arrays
    bool operator==(const array<T, N>& other) const {
        for (size_t i = 0; i < N; i++) {
            if (this->data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    array<uint32_t, 5> arr1 {1, 2, 3, 4, 5};
    arr1[0] = 0;
    assert((arr1[0] == 0));  // Modifying and checking an element

    array<uint32_t, 5> arr2 {6, 7, 8, 9, 10};
    array<uint32_t, 5> arr3 = arr1 + arr2;
    assert((arr3.size() == 5));  // Ensuring size is correct after operation
    assert((arr3 == array<uint32_t, 5>{6, 9, 11, 13, 15}));  // Addition and comparison

    array<uint32_t, 5> arr4 = arr2 - arr1;
    assert((arr4 == array<uint32_t, 5>{6, 5, 5, 5, 5}));  // Correct assertion for subtraction

    return EXIT_SUCCESS;
}
