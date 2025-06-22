# Vectors in C++ for DSA Preparation (without `std::`)

## 1. What is a Vector?
A vector is a dynamic array that can resize itself automatically when elements are added or removed.  
- Contiguous memory like arrays, but size can grow/shrink.  
- Part of the C++ STL (Standard Template Library).  

### How is a Vector Stored in Memory?
- Internally uses a dynamically allocated array.  
- When capacity is exceeded, it allocates a new larger array and copies elements (usually doubles capacity).  

---

## 2. Vector Declaration & Basic Operations
### (a) Including Vector Header
```cpp
#include <vector>
using namespace std; // To avoid writing std:: everywhere
```

### (b) Different Ways to Declare a Vector
```cpp
vector<int> vec1;               // Empty vector
vector<int> vec2(5);            // Vector of size 5 (all 0)
vector<int> vec3(5, 10);        // Vector of size 5 (all 10)
vector<int> vec4 = {1, 2, 3};   // Initialized with values
vector<int> vec5(vec4);         // Copy of vec4
```

### (c) Common Vector Operations
| Function | Description |
|----------|-------------|
| `vec.push_back(x)` | Add `x` at the end |
| `vec.pop_back()` | Remove last element |
| `vec.size()` | Current number of elements |
| `vec.capacity()` | Current storage capacity |
| `vec.empty()` | Returns `true` if empty |
| `vec.front()` | First element |
| `vec.back()` | Last element |
| `vec.clear()` | Remove all elements |
| `vec.resize(n)` | Change size to `n` |
| `vec.insert(it, x)` | Insert `x` at iterator `it` |
| `vec.erase(it)` | Remove element at iterator `it` |

---

## 3. Dynamic Resizing in Vectors
- Vectors automatically resize when `push_back()` exceeds capacity.  
- Capacity (total allocated space) vs Size (actual elements stored).  
- Amortized O(1) time for `push_back()` (due to doubling strategy).  

### Example:
```cpp
vector<int> vec;
for (int i = 0; i < 10; i++) {
    vec.push_back(i);
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;
}
```
Possible Output:
```
Size: 1, Capacity: 1  
Size: 2, Capacity: 2  
Size: 3, Capacity: 4  
Size: 4, Capacity: 4  
Size: 5, Capacity: 8  
...  
```

---

## 4. Example Problem with Solution
### Problem: Find the Second Largest Element in a Vector
```cpp
#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

int secondLargest(vector<int>& vec) {
    int first = INT_MIN, second = INT_MIN;
    for (int num : vec) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num != first) {
            second = num;
        }
    }
    return second;
}

int main() {
    vector<int> vec = {5, 2, 9, 1, 7, 9};
    cout << "Second largest: " << secondLargest(vec) << endl;
    return 0;
}
```
Output:
```
Second largest: 7
```

---

## 5. Three Practice Problems
### Easy: Remove Duplicates from Sorted Vector
Given a sorted vector, remove duplicates in-place and return new size.
```cpp
int removeDuplicates(vector<int>& vec) {
    if (vec.empty()) return 0;
    int j = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] != vec[j]) {
            j++;
            vec[j] = vec[i];
        }
    }
    return j + 1;
}
```

### Medium: Rotate Vector by K Steps
Rotate the vector to the right by `k` steps.
```cpp
void rotate(vector<int>& vec, int k) {
    int n = vec.size();
    k %= n;
    reverse(vec.begin(), vec.end());
    reverse(vec.begin(), vec.begin() + k);
    reverse(vec.begin() + k, vec.end());
}
```

### Hard: Maximum Sum Subarray (Kadane's Algorithm)
Find the contiguous subarray with the largest sum.
```cpp
int maxSubarraySum(vector<int>& vec) {
    int maxSum = vec[0], currentSum = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        currentSum = max(vec[i], currentSum + vec[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}
```

22. How would you generalize a function to work with both arrays and vectors?
Answer: Use templates:

cpp
template <typename Container>
void print(const Container& c) {
    for (auto x : c) cout << x << " ";
}

---

## 6. Key Takeaways
✅ Dynamic resizing makes vectors flexible.  
✅ Preferred over raw arrays in most cases (automatic memory management).  
✅ Use `push_back()` and `pop_back()` for efficient insertion/deletion at the end.  
✅ Iterators (`begin()`, `end()`) allow easy traversal and STL algorithm usage.  

Would you like more vector problems or explanations? 😊