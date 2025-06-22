# Arrays in C++ for DSA Preparation

## 1. What is an Array?
An array is a contiguous block of memory that stores multiple elements of the same data type.  
- Elements are accessed using an index (starting from `0`).  
- Fixed size at compile time (unless dynamically allocated).  

### How is an Array Stored in Memory?
- Memory is allocated contiguously (all elements are stored in adjacent memory locations).  
- The address of the `i-th` element can be calculated as:  
  
  Address of arr[i] = Base Address + (i * size_of_data_type)
  
- Example:  
  cpp
  int arr[5] = {10, 20, 30, 40, 50};
  
  
  Memory Layout:
  Index:   0   1   2   3   4
  Value: 10  20  30  40  50
  Address: 100 104 108 112 116 (assuming int takes 4 bytes)
  

---

## 2. Basic STL for Arrays (C++ `<array>`)
The C++ Standard Template Library (STL) provides a fixed-size array container:
cpp
#include <array>

std::array<int, 5> arr = {1, 2, 3, 4, 5};

### Common STL Array Operations:
| Function | Description |
|----------|-------------|
| `arr.at(i)` | Access element at index `i` (with bounds checking) |
| `arr[i]` | Access element at index `i` (no bounds checking) |
| `arr.front()` | First element |
| `arr.back()` | Last element |
| `arr.size()` | Number of elements |
| `arr.fill(val)` | Fill array with `val` |

---

## 3. Different Ways to Declare Arrays
### (a) Static Array (Fixed Size)
cpp
int arr1[5];               // Uninitialized
int arr2[5] = {1, 2, 3};   // Partial initialization (rest are 0)
int arr3[] = {1, 2, 3, 4}; // Size inferred


### (b) Dynamic Array (Heap Allocation)
cpp
int* arr = new int[5];    // Allocate
arr[0] = 10;              // Assign
delete[] arr;             // Deallocate (to prevent memory leaks)


### (c) STL Array (Fixed Size)
cpp
#include <array>
std::array<int, 5> arr = {1, 2, 3, 4, 5};


### (d) STL Vector (Dynamic Array)
cpp
#include <vector>
std::vector<int> vec = {1, 2, 3};  // Resizable
vec.push_back(4);                  // Add element


---

## 4. Dynamic Allocation of Arrays
### (a) Using `new` and `delete`
cpp
int n = 5;
int* arr = new int[n];  // Allocate
arr[0] = 10;            // Use
delete[] arr;           // Free memory


### (b) Using `malloc` and `free` (C-style)
cpp
int* arr = (int*)malloc(n * sizeof(int));
arr[0] = 10;
free(arr);


---

## 5. Example Problem with Solution
### Problem: Find the Maximum Element in an Array
cpp
#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Max element: " << findMax(arr, n) << endl;
    return 0;
}

Output:

Max element: 9


---

## 6. Three Practice Problems
### Easy: Reverse an Array
Given an array, reverse it in-place.
cpp
void reverseArray(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}


### Medium: Find Missing Number in an Array of 1 to N
Given an array of size `N-1` containing numbers from `1` to `N` (one missing), find the missing number.
cpp
int missingNumber(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2;  // Sum of 1 to N
    for (int i = 0; i < n; i++) {
        total -= arr[i];
    }
    return total;
}


### Hard: Kadane's Algorithm (Maximum Subarray Sum)
Find the contiguous subarray with the largest sum.
cpp
int maxSubarraySum(int arr[], int n) {
    int maxSum = arr[0], currentSum = arr[0];
    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}


---

### Final Tips for DSA with Arrays:
✅ Master traversal, insertion, deletion in arrays.  
✅ Learn two-pointer techniques (used in many problems).  
✅ Practice prefix sum and sliding window concepts.  
✅ Understand time and space complexity for array operations.  

Would you like more problems or explanations on any specific topic? 😊