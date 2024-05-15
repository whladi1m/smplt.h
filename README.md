# smplt.h - Simple Mini Library

`smplt.h` is a lightweight C++ library providing simple functionalities like sorting algorithms, factorial calculation, finding roots of functions, and generating random numbers and vectors.

## Functions:

### Sorting Algorithms:
1. **Bubble Sort**: Sorts a vector of elements in ascending order using the Bubble Sort algorithm.
```cpp
#include "smplt.h"
#include <iostream>

int main() {
    std::vector<int> numbers = {5, 2, 7, 3, 9, 1};
    smplt::bubbleSort(numbers);
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```
2. **Selection Sort**: Sorts a vector of elements in ascending order using the Selection Sort algorithm.
```cpp
#include "smplt.h"
#include <iostream>

int main() {
    std::vector<int> numbers = {5, 2, 7, 3, 9, 1};
    smplt::selectionSort(numbers);
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```
### Math:
3. **Factorial**: Finds fib. numbers.
```cpp
#include "smplt.h"
#include <iostream>

int main() {
    int n = 5;
    std::cout << "Factorial of " << n << " is: " << smplt::factorial(n) << std::endl;
}
```
4. **Find root of number**: Finds root of number.
```cpp
#include "smplt.h"
#include <iostream>

int main() {
    double root = smplt::findRoot([](double x) { return x * x - 4; }, 0, 3);
    std::cout << "Root of the function f(x) = x^2 - 4 is: " << root << std::endl;
}
```

**MORE EXAMPLES IN MAIN.CPP**
