## ✅ **Selection Sort – Theory**

### 🔹 Concept:

In **Selection Sort**, we repeatedly **find the minimum element** from the unsorted part of the array and **move it to the beginning**.

You divide the array into two parts:

1. **Sorted** part (initially empty)
2. **Unsorted** part (entire array at first)

### 🔹 Time Complexity:

* **Best-case, Worst-case, Average-case**: O(n²)
* **Space**: O(1) — In-place

---

### 🔹 Working Example:

Let’s sort:
`arr = [64, 25, 12, 22, 11]`

**Pass 1**:
Find minimum in `[64, 25, 12, 22, 11]` → 11
Swap 11 with 64 → `[11, 25, 12, 22, 64]`

**Pass 2**:
Find min in `[25, 12, 22, 64]` → 12
Swap 12 with 25 → `[11, 12, 25, 22, 64]`

**Pass 3**:
Find min in `[25, 22, 64]` → 22
Swap 22 with 25 → `[11, 12, 22, 25, 64]`

**Pass 4**:
Find min in `[25, 64]` → 25
No swap needed

**Sorted Array**: `[11, 12, 22, 25, 64]`

---

## ✅ Selection Sort – C++ Code

```cpp
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // Find the index of minimum element in remaining unsorted array
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap the found min with current element
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```
