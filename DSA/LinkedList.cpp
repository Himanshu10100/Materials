## ✅ **Topic: Linked List (C++)**

### 🔹 **1. What is a Linked List?**

A linear data structure where elements (nodes) are stored in memory non-contiguously, and each node points to the next.

```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
```

---

### 🔹 **2. Types of Linked Lists**

* **Singly Linked List**
* **Doubly Linked List**
* **Circular Linked List**

---

### 🔹 **3. Basic Operations**

* **Insert** (at beginning, end, position)
* **Delete** (at beginning, end, position)
* **Traverse / Print**
* **Search**
* **Length of List**

```cpp
// Insert at beginning
void insertAtHead(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
```

---

### 🔹 **4. Important Concepts and Examples**

#### ✅ Reverse a Linked List (Iterative & Recursive)

```cpp
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while(curr) {
        Node* nextPtr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPtr;
    }
    return prev;
}
```

#### ✅ Detect Loop (Floyd's Cycle Detection)

```cpp
bool hasCycle(Node *head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
```

#### ✅ Find Middle of Linked List (Tortoise-Hare)

```cpp
Node* middleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

#### ✅ Merge Two Sorted Lists

```cpp
Node* merge(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;
    while(l1 && l2) {
        if(l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1) ? l1 : l2;
    return dummy.next;
}
```

#### ✅ Check if Linked List is Palindrome

Use stack or reverse second half and compare.

---

### 🔹 **5. Advanced Concepts**

* Copy a Linked List with Random Pointer
* Intersection Point of Two Linked Lists
* Detect and Remove Loop
* LRU Cache (uses Doubly Linked List + HashMap)

---

## 🧠 3 Linked List Practice Problems

1. 🔗 **[Reverse a Linked List](https://leetcode.com/problems/reverse-linked-list/)**
   *Easy — Must know how to reverse using both iterative and recursion.*

2. 🧠 **[Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)**
   *Medium — Use Floyd’s cycle detection to find the start of the loop.*

3. 🔁 **[Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)**
   *Hard — Use Min Heap or divide and conquer.*

---