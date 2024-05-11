#include <iostream>
#include "smplt.h"

int main() {
    // Example of sorting algorithms
    std::vector<int> numbers = {5, 2, 7, 3, 9, 1};

    // Bubble Sort
    std::vector<int> numbers_bubble = numbers; // Copy of original numbers
    smplt::bubbleSort(numbers_bubble);
    std::cout << "Bubble Sort: ";
    for (int num : numbers_bubble) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Selection Sort
    std::vector<int> numbers_selection = numbers; // Copy of original numbers
    smplt::selectionSort(numbers_selection);
    std::cout << "Selection Sort: ";
    for (int num : numbers_selection) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Insertion Sort
    std::vector<int> numbers_insertion = numbers; // Copy of original numbers
    smplt::insertionSort(numbers_insertion);
    std::cout << "Insertion Sort: ";
    for (int num : numbers_insertion) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Merge Sort
    std::vector<int> numbers_merge = numbers; // Copy of original numbers
    smplt::mergeSort(numbers_merge, 0, numbers_merge.size() - 1);
    std::cout << "Merge Sort: ";
    for (int num : numbers_merge) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example of calculating factorial
    int n = 5;
    std::cout << "Factorial of " << n << " is: " << smplt::factorial(n) << std::endl;

    // Example of finding the root of a function
    double root = smplt::findRoot([](double x) { return x * x - 4; }, 0, 3);
    std::cout << "Root of the function f(x) = x^2 - 4 is: " << root << std::endl;

    // Example of generating random numbers and vectors
    std::cout << "Random number between 1 and 100: " << smplt::generateRandomNumber(1, 100) << std::endl;
    std::vector<int> randomVector = smplt::generateRandomVector(5, 1, 100);
    std::cout << "Random vector: ";
    for (int num : randomVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
