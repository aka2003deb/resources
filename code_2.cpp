#include <cassert>
#include <initializer_list>
#include <algorithm>
#include <cstdint>  // Include for uint32_t

using namespace std;

template<typename T, size_t N>
class MyArray {
private:
    T data[N];  // Internal data storage
public:
    // Default constructor
    MyArray() {}

    // Constructor with initializer list for easy initialization
    MyArray(initializer_list<T> list) {
        assert(list.size() == N);  // Ensure the list has exactly N elements
        copy(list.begin(), list.end(), data);
    }

    // Access and modify elements by index
    T& operator[](size_t index) {
        assert(index < N);  // Ensure the index is within bounds
        return data[index];
    }

    // Read-only element access
    const T& operator[](size_t index) const {
        assert(index < N);  // Ensure the index is within bounds
        return data[index];
    }

    // Get the size of the array
    constexpr size_t size() const {
        return N;
    }

    // Add two arrays element-wise
    MyArray<T, N> operator+(const MyArray<T, N>& other) const {
        MyArray<T, N> result;
        for (size_t i = 0; i < N; i++) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    // Subtract two arrays element-wise
    MyArray<T, N> operator-(const MyArray<T, N>& other) const {
        MyArray<T, N> result;
        for (size_t i = 0; i < N; i++) {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    // Compare two arrays for equality
    bool operator==(const MyArray<T, N>& other) const {
        for (size_t i = 0; i < N; i++) {
            if (this->data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    MyArray<uint32_t, 5> arr1 {1, 2, 3, 4, 5};
    arr1[0] = 0;  // Modify the first element

    MyArray<uint32_t, 5> arr2 {6, 7, 8, 9, 10};
    MyArray<uint32_t, 5> arr3 = arr1 + arr2;  // Test addition of arrays
    assert((arr3 == MyArray<uint32_t, 5>{0 + 6, 2 + 7, 3 + 8, 4 + 9, 5 + 10}));  // Addition and comparison

    MyArray<uint32_t, 5> arr4 = arr2 - arr1;  // Test subtraction of arrays
    assert((arr4 == MyArray<uint32_t, 5>{6 - 0, 7 - 2, 8 - 3, 9 - 4, 10 - 5}));  // Subtraction result check

    return 0;  // Use 0 to indicate successful execution
}
