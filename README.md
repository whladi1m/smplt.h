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
1. **Selection Sort**: Sorts a vector of elements in ascending order using the Selection Sort algorithm.
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

**MORE EXAMPLES IN MAIN.CPP**
