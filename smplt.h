#ifndef SMPLT_H
#define SMPLT_H

#include <vector>
#include <algorithm>
#include <random>

#include <Windows.h> // for messages or another stuff
#include <chrono> // for time stuff

/*
ENUMS:
    MB_ICONINFORMATION
    MB_ICONWARNING
    MB_ICONERROR
    MB_ICONQUESTION
*/

namespace smplt {

    // Bubble Sort
    template<typename T>
    void bubbleSort(std::vector<T>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Selection Sort
    template<typename T>
    void selectionSort(std::vector<T>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(arr[i], arr[minIndex]);
            }
        }
    }

    // Insertion Sort
    template<typename T>
    void insertionSort(std::vector<T>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

    // Merge Sort
    template<typename T>
    void merge(std::vector<T>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<T> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    template<typename T>
    void mergeSort(std::vector<T>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    // Generate a random vector of given size with elements in a specified range
    std::vector<int> generateRandomVector(int size, int minVal, int maxVal) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(minVal, maxVal);

        std::vector<int> randomVector(size);
        for (int i = 0; i < size; ++i) {
            randomVector[i] = distribution(gen);
        }
        return randomVector;
    }

    // Generate a random number in a specified range
    int generateRandomNumber(int minVal, int maxVal) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(minVal, maxVal);

        return distribution(gen);
    }

    // MATH
    // Calculate factorial of a number
    unsigned long long factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        unsigned long long fact = 1;
        for (int i = 2; i <= n; ++i) {
            fact *= i;
        }
        return fact;
    }

    // Function to find the root using the bisection method
    double findRoot(double (*f)(double), double a, double b, double epsilon = 1e-6) {
        if (f(a) * f(b) >= 0) {
            throw std::runtime_error("Root is not guaranteed to exist in the given interval.");
        }

        double c = a;
        while ((b - a) >= epsilon) {
            c = (a + b) / 2; // Find the midpoint
            if (f(c) == 0.0) // Check if midpoint is root
                break;
            else if (f(c) * f(a) < 0) // Decide the side to repeat the steps
                b = c;
            else
                a = c;
        }
        return c;
    }

    // Function to check if number is the palidrome
    
    /*
    PS:
    See https://en.wikipedia.org/wiki/Palindromic_number
    */

    bool isPalidrome(int number) {
        int reversed = 0, remainder, original;

        original = number;

        while (number != 0) {
            remainder = number % 10;
            reversed = reversed * 10 + remainder;
            number /= 10;
        }

        if (original == reversed) {
            return true;
        } else {
            return false;
        }
    }

    bool isPrime(int number) {
        if (number < 0) {
            throw std::runtime_error("Cannot complete isPrime() because number is not positive.");
        }

        int i;
        bool isPRM = true;

        for (i = 2; i <= number / 2; ++i) {
            if (number % i == 0) {
                isPRM = false;
                break;
            }
        }

        return isPRM;
    }

    // Matrix multiplication
    /*
    PS:
    See https://en.wikipedia.org/wiki/Matrix_multiplication
    */

    // Function to perform matrix multiplication
    std::vector<std::vector<int>> matrixMultiplication(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
        int m = A.size();
        int n = A[0].size();
        int p = B[0].size();

        std::vector<std::vector<int>> result(m, std::vector<int>(p, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < n; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return result;
    }

    // Function to calculate the time difference in milliseconds
    long long timeDifference(const std::chrono::steady_clock::time_point& start, const std::chrono::steady_clock::time_point& end) {
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }

    // Function to calculate the time difference in seconds
    long long calculateTimeDifferenceInSeconds(const std::chrono::steady_clock::time_point& start, const std::chrono::steady_clock::time_point& end) {
        return std::chrono::duration_cast<std::chrono::seconds>(end - start).count(); // just replace std::chrono::seconds with your
    }

    // VECTOR/ARRAY STUFF
    // int size = sizeof(arr) / sizeof(arr[0]);
    // Function to find the maximum number in an array
    int findMaxInArray(int arr[], int size) {
        if (size == 0) {
            throw std::runtime_error("Array is empty.");
        }
        
        int maxNum = arr[0];
        
        for (int i = 1; i < size; ++i) {
            if (arr[i] > maxNum) {
                maxNum = arr[i];
            }
        }
        
        return maxNum;
    }

    // Function to find the maximum number in a vector
    int findMaxInVector(const std::vector<int>& vec) {
        if (vec.empty()) {
            throw std::runtime_error("Vector is empty.");
        }
        
        auto maxElement = std::max_element(vec.begin(), vec.end());
        
        return *maxElement;
    }

    // GRAPHICS/WINDOWS STUFF
    void showMessage(const char* title, const char* message) {
        MessageBoxA(NULL, message, title, MB_OK | MB_ICONINFORMATION);
    }

    void showWarningMessage(const char* title, const char* message) {
        MessageBoxA(NULL, message, title, MB_OK | MB_ICONWARNING);
    }

    void showErrorMessage(const char* title, const char* message) {
        MessageBoxA(NULL, message, title, MB_OK | MB_ICONERROR);
    }

    void showQuestionMessage(const char* title, const char* message) {
        MessageBoxA(NULL, message, title, MB_OK | MB_ICONQUESTION);
    }

} // namespace smplt

#endif // SMPLT_H
