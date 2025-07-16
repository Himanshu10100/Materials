## ✅ **Quick Sort – Theory**

### 🔹 Concept:

**Quick Sort** is a **Divide and Conquer** algorithm that:

1. Picks a **pivot** element,
2. Partitions the array so that:

   * Elements smaller than pivot go to the left,
   * Elements greater go to the right,
3. Recursively applies the same logic to subarrays.

> Unlike Merge Sort, Quick Sort is **in-place** and doesn’t require extra space.

---

### 🔹 Time & Space Complexity:

| Case    | Time       | Space                  |
| ------- | ---------- | ---------------------- |
| Best    | O(n log n) | O(log n)               |
| Average | O(n log n) | O(log n)               |
| Worst   | O(n²)      | O(log n) — stack space |

> Worst case occurs when the pivot is the smallest or largest every time (can be optimized with randomized pivot or median of three).

---

## 🔹 Example Walkthrough

Sort: `arr = [10, 7, 8, 9, 1, 5]`

* Choose pivot = last element (5)
* Partition: move smaller to left of pivot → `[1] [5] [10, 7, 8, 9]`
* Recursively sort both sides.

---

## ✅ Quick Sort – C++ Code

```cpp
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pivot
    int i = low - 1;         // index of smaller element

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // place pivot at correct position
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before & after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```

---

### 🔹 When to use Quick Sort?

* When **space** is limited (in-place sort)
* When average case performance is acceptable
* Not stable, but very **fast in practice**

---

Now that you’ve completed:
✅ Bubble
✅ Selection
✅ Insertion
✅ Merge
✅ Quick