## ✅ **Topic: Stack (with STL in C++)**

A **stack** is a linear data structure that follows **LIFO (Last In First Out)**.

### 🔹 1. **C++ STL Stack**

```cpp
#include <stack>
stack<int> st;

// Operations
st.push(10);
st.pop();
int top = st.top();
bool isEmpty = st.empty();
```

---

### 🔹 2. **Stack Use Cases**

* Undo operations in editors
* Expression evaluation
* Parentheses matching
* Backtracking (DFS)
* Function call stack

---

## 🔸 Important Stack Concepts with Examples

---

### ✅ **1. Valid Parentheses**

Check if the string has valid opening and closing brackets.

```cpp
bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if(st.empty()) return false;
            char top = st.top(); st.pop();
            if((c == ')' && top != '(') || 
               (c == ']' && top != '[') ||
               (c == '}' && top != '{')) return false;
        }
    }
    return st.empty();
}
```

---

### ✅ **2. Next Greater Element**

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    vector<int> res(nums.size(), -1);
    for(int i = 0; i < nums.size(); i++) {
        while(!st.empty() && nums[i] > nums[st.top()]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
```

---

### ✅ **3. Min Stack (Get min in O(1))**

```cpp
class MinStack {
    stack<int> st, minSt;
public:
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top()) minSt.push(val);
    }
    void pop() {
        if(st.top() == minSt.top()) minSt.pop();
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return minSt.top(); }
};
```

---

### ✅ **4. Largest Rectangle in Histogram**

Use monotonic increasing stack to track width.

```cpp
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxA = 0;
    heights.push_back(0); // sentinel
    for(int i = 0; i < heights.size(); i++) {
        while(!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxA = max(maxA, h * w);
        }
        st.push(i);
    }
    return maxA;
}
```

---

### ✅ **5. Implement Stack using Queues / Queue using Stacks**

Good for object-oriented implementation and interview questions.

---

## 🧠 Bonus: STL Stack Tips

* Use `stack<T> s;` for LIFO operations.
* Use `vector` or `deque` if random access is needed.
* Stack is backed by `deque` by default in C++ STL.

---

## 🔥 3 Practice Questions to Solve

1. 🔗 [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) — *Easy*
   Use stack to match open and close brackets.

2. 🔥 [Min Stack](https://leetcode.com/problems/min-stack/) — *Medium*
   Get `min` in O(1) time using two stacks.

3. 🧱 [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) — *Hard*
   Classic stack problem with monotonic stack technique.
