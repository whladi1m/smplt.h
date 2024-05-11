#ifndef SMPLT_H
#define SMPLT_H

#include <vector>
#include <algorithm>
#include <random>

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

} // namespace smplt

#endif // SMPLT_H
