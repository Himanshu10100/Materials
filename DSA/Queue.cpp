## ✅ **Topic: Queue (with STL in C++)**

A **Queue** is a linear data structure that follows **FIFO (First In First Out)**.

---

## 🔹 1. **C++ STL Queue Basics**

```cpp
#include <queue>
queue<int> q;

// Basic operations
q.push(10);     // enqueue
q.pop();        // dequeue
int front = q.front();  // peek
bool empty = q.empty();
```

---

## 🔹 2. **Types of Queues**

| Type               | Description                        |
| ------------------ | ---------------------------------- |
| **Simple Queue**   | FIFO, one end insert, other remove |
| **Circular Queue** | Reuses space in array              |
| **Deque**          | Insert/delete from both ends       |
| **Priority Queue** | Highest priority served first      |

---

## 🔹 3. **Implement Queue using Array**

Circular Queue example:

```cpp
class MyQueue {
    int* arr;
    int front, rear, size, capacity;
public:
    MyQueue(int cap) {
        capacity = cap;
        arr = new int[cap];
        front = size = 0;
        rear = cap - 1;
    }

    bool enqueue(int x) {
        if (size == capacity) return false;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
        return true;
    }

    bool dequeue() {
        if (size == 0) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        if (size == 0) return -1;
        return arr[front];
    }
};
```

---

## 🔹 4. **Double-Ended Queue (Deque)**

```cpp
#include <deque>
deque<int> dq;

dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
```

Used in:

* Sliding window problems
* Monotonic queues

---

## 🔹 5. **Priority Queue**

### Max Heap (default):

```cpp
priority_queue<int> pq;
pq.push(3); pq.push(1); pq.push(4);
pq.top();   // 4
```

### Min Heap:

```cpp
priority_queue<int, vector<int>, greater<int>> minPQ;
```

---

## 🔹 6. **Queue Applications**

| Problem Type               | Queue Type Used  |
| -------------------------- | ---------------- |
| **BFS (Graph)**            | Simple Queue     |
| **Sliding Window Maximum** | Deque            |
| **CPU Scheduling**         | Priority Queue   |
| **Cache (LRU)**            | Deque + Map      |
| **Task Scheduling**        | Topological Sort |

---

## 🔹 7. **Important Example: BFS using Queue**

```cpp
void bfs(int start, vector<int> adj[], vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
}
```

---

## 🧠 3 Practice Questions to Solve

1. 🔁 **[Implement Circular Queue](https://leetcode.com/problems/design-circular-queue/)** – *Medium*
   Learn how circular queue avoids wasted space.

2. 🎢 **[Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)** – *Hard*
   Use deque to keep track of max in a sliding window.

3. 🚦 **[Number of Recent Calls](https://leetcode.com/problems/number-of-recent-calls/)** – *Easy*
   Simulate incoming request using queue.