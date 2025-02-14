#include <iostream>

// Original function for integers
int add(int a, int b) {
    return a + b;
}

// Overloaded function for characters
int add(char a, char b) {
    // Explicitly convert chars to int before adding
    return static_cast<int>(a) + static_cast<int>(b);
}

int main() {
    char x = 'a'; // ASCII value 97
    char y = 'b'; // ASCII value 98

    // Calling the overloaded add function with char parameters
    int result = add(x, y);
    std::cout << "Result of adding " << x << " and " << y << " is " << result << std::endl;

    // Example using integers directly
    std::cout << "Result of adding 10 and 20 is " << add(10, 20) << std::endl;

    return 0;
}
