## ✅ **Insertion Sort – Theory**

### 🔹 Concept:

**Insertion Sort** builds the final sorted array **one element at a time**. It takes each element and **inserts it into its correct position** in the sorted part of the array (just like sorting playing cards in hand).

It works well on **small or nearly sorted** datasets.

### 🔹 Time Complexity:

* **Best-case**: O(n) — when array is already sorted
* **Average & Worst-case**: O(n²)
* **Space**: O(1) — In-place

---

### 🔹 Working Example:

Let’s sort:
`arr = [5, 3, 4, 1, 2]`

**Pass 1** (i=1):
Compare 3 with 5 → Shift 5 → Insert 3 → `[3, 5, 4, 1, 2]`

**Pass 2** (i=2):
Compare 4 with 5 → Shift 5
Compare 4 with 3 → OK → Insert 4 → `[3, 4, 5, 1, 2]`

**Pass 3** (i=3):
Compare 1 with 5, 4, 3 → Shift them all → Insert 1 → `[1, 3, 4, 5, 2]`

**Pass 4** (i=4):
Compare 2 with 5, 4, 3 → Shift → Insert 2 → `[1, 2, 3, 4, 5]`

---

## ✅ Insertion Sort – C++ Code

```cpp
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are > key, one position ahead
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```