## 🔶 1. **What is a Priority Queue?**

A **Priority Queue** is a data structure where each element has a **priority**. Elements are **served based on priority** (not just insertion order).

There are two main types:

* **Max Priority Queue**: Highest priority (maximum value) is served first.
* **Min Priority Queue**: Lowest priority (minimum value) is served first.

---

## 🔶 2. **Theory Behind Min/Max Priority Queue**

Priority queues are often implemented using **heaps**:

* **Max-Heap**: Root has the maximum value.
* **Min-Heap**: Root has the minimum value.

### Operations:

| Operation   | Time Complexity | Description                        |
| ----------- | --------------- | ---------------------------------- |
| `insert()`  | O(log n)        | Add element while maintaining heap |
| `getTop()`  | O(1)            | Return top (min/max) element       |
| `remove()`  | O(log n)        | Remove top element                 |
| `heapify()` | O(n)            | Build heap from array              |

---

## 🔶 3. **Example to Understand**

### 📌 Let's build a **Min Priority Queue** with elements:

```
[5, 1, 3, 4, 2]
```

### Step-by-step (as Min-Heap):

1. Insert 5 → \[5]
2. Insert 1 → \[1, 5]
3. Insert 3 → \[1, 5, 3]
4. Insert 4 → \[1, 4, 3, 5]
5. Insert 2 → \[1, 2, 3, 5, 4]

**Top element (`getMin`) = 1**

**Remove top** → Re-heapify:

* Remove 1 → New root is 4 → heapify → \[2, 4, 3, 5]

---

## 🔶 4. **Visualization**

You can visualize it like a binary tree (heap):

### Min-Heap Tree

```
        1
      /   \
     2     3
    / \
   5   4
```

Each parent is **less than** its children.

### Max-Heap Tree

```
        5
      /   \
     4     3
    / \
   1   2
```

Each parent is **greater than** its children.

---

## 🔶 5. **STL in C++**

C++ provides `priority_queue` in `<queue>`.

### ✅ Max Priority Queue (default)

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(5);
    pq.push(1);
    pq.push(3);

    cout << "Top: " << pq.top() << endl; // 5

    pq.pop();

    cout << "Top after pop: " << pq.top() << endl; // 3

    return 0;
}
```

### ✅ Min Priority Queue

Use a custom comparator or negative values.

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(5);
    minPQ.push(1);
    minPQ.push(3);

    cout << "Top: " << minPQ.top() << endl; // 1

    minPQ.pop();

    cout << "Top after pop: " << minPQ.top() << endl; // 3

    return 0;
}
```

---

## 🔶 6. **Use Cases**

* Dijkstra’s algorithm (Min Priority Queue)
* Huffman Coding
* Scheduling tasks
* A\* search algorithm
* Bandwidth management

---

## ✅ Summary

| Type               | STL Syntax                                       |
| ------------------ | ------------------------------------------------ |
| Max Priority Queue | `priority_queue<int>`                            |
| Min Priority Queue | `priority_queue<int, vector<int>, greater<int>>` |

---