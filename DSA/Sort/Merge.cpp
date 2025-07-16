## ✅ **Merge Sort – Theory**

### 🔹 Concept:

**Merge Sort** is a **Divide and Conquer** algorithm that:

1. Divides the array into halves recursively,
2. Sorts the halves,
3. Merges them back in sorted order.

### 🔹 Time Complexity:

* **Best, Average, Worst**: O(n log n)
* **Space**: O(n) – because of the temporary arrays used in merging

### 🔹 Why it's better than Bubble/Selection/Insertion?

* It’s much faster on large datasets.
* Stable and predictable performance.

---

## 🔹 Working Example:

Let's sort:
`arr = [38, 27, 43, 3, 9, 82, 10]`

```
Divide:
[38, 27, 43, 3, 9, 82, 10]
=> [38, 27, 43] and [3, 9, 82, 10]
=> [38], [27, 43] and [3, 9], [82, 10]
=> Merge: [27, 38, 43], [3, 9], [10, 82]
=> Merge: [27, 38, 43], [3, 9, 10, 82]
=> Final Merge: [3, 9, 10, 27, 38, 43, 82]
```

---

## ✅ Merge Sort – C++ Code

```cpp
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;  // Size of left subarray
    int n2 = r - m;      // Size of right subarray

    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Merge temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // Copy remaining elements
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge sorted halves
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```