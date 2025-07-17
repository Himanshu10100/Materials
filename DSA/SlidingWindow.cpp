## ✅ **Topic: Sliding Window Technique (C++)**

---

### 🔹 What is Sliding Window?

A **sliding window** is a **subarray or subset** of elements that "slides" over the input. It’s useful to avoid nested loops (O(n²)) and bring down the complexity to **O(n)**.

There are two main types:

* **Fixed Window Size**
* **Variable (Dynamic) Window Size**

---

## 📌 Example 1: Fixed Size Window

### 🧠 Problem:

Find the **maximum sum of a subarray of size k**
**Input**: `arr = [2, 1, 5, 1, 3, 2], k = 3`
**Brute Force**: check all subarrays of size 3 → O(n \* k)
**Sliding Window**: O(n)

### 🔄 Sliding Window Explanation:

* Start by summing the first `k` elements
* Slide the window by **removing** first and **adding** next element

#### Step-by-step:

```
[2, 1, 5] → sum = 8  
[1, 5, 1] → sum = 7  
[5, 1, 3] → sum = 9 ← max  
[1, 3, 2] → sum = 6  
Max = 9
```

---

### ✅ C++ Code – Fixed Size Window

```cpp
#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarrayOfSizeK(vector<int>& arr, int k) {
    int windowSum = 0, maxSum = 0;

    for(int i = 0; i < k; i++) windowSum += arr[i];
    maxSum = windowSum;

    for(int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k];  // slide window
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Max sum of size " << k << ": " << maxSumSubarrayOfSizeK(arr, k);
    return 0;
}
```

---

## 📌 Example 2: Variable Size Window

### 🧠 Problem:

Find the **smallest subarray with sum ≥ target**

**Input**: `arr = [2, 3, 1, 2, 4, 3], target = 7`
**Output**: `2` → `[4, 3]`

#### Step-by-step:

* Expand window while sum < target
* Once sum ≥ target, try to **shrink** window from the left

---

### ✅ C++ Code – Variable Size Window

```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int start = 0, sum = 0, minLen = INT_MAX;

    for(int end = 0; end < nums.size(); end++) {
        sum += nums[end];
        while(sum >= target) {
            minLen = min(minLen, end - start + 1);
            sum -= nums[start++];
        }
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}
```

---

## ✅ Where to Use Sliding Window?

| Category            | Example Use Case                                     |
| ------------------- | ---------------------------------------------------- |
| **Fixed Size**      | Maximum sum of k elements, Average, Min/Max          |
| **Dynamic Size**    | Smallest subarray with condition (like sum ≥ target) |
| **String Problems** | Longest substring with no repeats, permutations      |
| **Frequency/Count** | Anagrams, Character replacement, Repeating chars     |

---

## 🔁 Sliding Window Patterns & Problems

| Pattern           | Problem                                                                                                                                         |
| ----------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| ✅ Fixed Window    | 🔹 [Maximum Sum of Subarray of Size K – Leetcode 643](https://leetcode.com/problems/maximum-average-subarray-i/)                                |
| ✅ Dynamic Window  | 🔹 [Minimum Size Subarray Sum – Leetcode 209](https://leetcode.com/problems/minimum-size-subarray-sum/)                                         |
| ✅ Count/Frequency | 🔹 [Longest Substring Without Repeating Characters – Leetcode 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) |
| ✅ HashMap-based   | 🔹 [Permutation in String – Leetcode 567](https://leetcode.com/problems/permutation-in-string/)                                                 |
| ✅ Binary Sliding  | 🔹 [Longest Repeating Character Replacement – Leetcode 424](https://leetcode.com/problems/longest-repeating-character-replacement/)             |
