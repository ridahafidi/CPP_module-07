
#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        // Create an array of integers
        Array<int> intArray(5);

        // Set values
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }

        // Print values
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Create an array of strings
        Array<std::string> strArray(3);

        // Set values
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "!";

        // Print values
        for (unsigned int i = 0; i < strArray.size(); i++) {
            std::cout << strArray[i] << " ";
        }
        std::cout << std::endl;

        // Access out-of-range index
        std::cout << intArray[10] << std::endl; // This will throw an exception
    } catch (const Array<int>::OutOfRange &e) {
        std::cerr << e.what() << std::endl;
    } catch (const Array<std::string>::OutOfRange &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}