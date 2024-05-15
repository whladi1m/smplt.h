#include <iostream>
#include <chrono>
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

    // Example of palindrome
    int num1 = 12321;
    bool isPalidrome = smplt::isPalidrome(num1);
    std::cout << isPalidrome;

    // Example of prime number
    int num2 = 17;
    bool isPrime = smplt::isPrime(num2);
    std::cout << isPrime;

    // Example of matrix multiplication
    std::vector<std::vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> B = {{7, 8}, {9, 10}, {11, 12}};
    std::vector<std::vector<int>> result = smplt::matrixMultiplication(A, B);

    // Displaying the result
    for (const auto& row : result) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // Example of time difference in milliseconds
    auto start = std::chrono::steady_clock::now();
    // Some operation or task
    auto end = std::chrono::steady_clock::now();
    long long duration = smplt::timeDifference(start, end);
    std::cout << "Time taken: " << duration << " milliseconds" << std::endl;

    // Example of find max in array
    int arr[] = {10, 20, 30, 40, 50};
    int sizeOfArray = sizeof(arr) / sizeof(arr[0]);
    int maxInArray = smplt::findMaxInArray(arr, sizeOfArray);
    std::cout << "Max number in array: " << maxInArray << std::endl;

    // Example of find max in vector
    std::vector<int> vec = {10, 20, 30, 40, 50};
    int maxInVector = smplt::findMaxInVector(vec);
    std::cout << "Max number in vector: " << maxInVector << std::endl;

    // Example of showing a message
    const char* title = "Information";
    const char* message = "Hello, this is a message box!";
    smplt::showMessage(title, message);
    smplt::showWarningMessage(title, message);
    smplt::showErrorMessage(title, message);
    smplt::showQuestionMessage(title, message);

    return 0;
}
