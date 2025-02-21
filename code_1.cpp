#include <iostream>

// Bring all standard library entities into the scope to avoid prefixing with std::
using namespace std;

// Define a template that allows any data type to be printed using operator+
template <typename T>
ostream& operator+(ostream& os, const T& val) {
    os << val;
    return os;
}

int main() {
    // Utilizing the overloaded operator+ to behave as operator<<
    cout + 5;  // Intended to work as cout << 5;
    cout + 5.5 + "\nThis Works!\n";  // Intended to work as cout << 5.5 << " This Works!\n";

    return 0;
}
