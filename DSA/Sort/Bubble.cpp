## ✅ **Bubble Sort – Theory**

### 🔹 Concept:

Bubble Sort repeatedly compares **adjacent elements** and **swaps them if they are in the wrong order**. After each full pass through the array, the **largest element “bubbles” to the end**.

### 🔹 Time Complexity:

* **Worst-case**: O(n²) – when the array is in reverse order
* **Best-case**: O(n) – when the array is already sorted (optimized version)
* **Space**: O(1) – In-place sorting

---

### 🔹 Working Example:

Let’s sort the array:
`arr = [5, 1, 4, 2, 8]`

**Pass 1**:

* Compare 5 and 1 → Swap → \[1, 5, 4, 2, 8]
* Compare 5 and 4 → Swap → \[1, 4, 5, 2, 8]
* Compare 5 and 2 → Swap → \[1, 4, 2, 5, 8]
* Compare 5 and 8 → No swap

**Pass 2**:

* Compare 1 and 4 → OK
* Compare 4 and 2 → Swap → \[1, 2, 4, 5, 8]
* Compare 4 and 5 → OK
* Compare 5 and 8 → OK

**Pass 3**:

* Compare 1 and 2 → OK
* Compare 2 and 4 → OK
* Compare 4 and 5 → OK
* Array is now sorted.

---

## ✅ Bubble Sort – C++ Code

Here’s the C++ implementation (optimized version):

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        bool swapped = false; // Optimization
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) break; // Stop if no swaps in pass
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```