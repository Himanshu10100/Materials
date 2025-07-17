## ✅ **Topic: Two Pointer Approach (C++)**

---

### 🔹 What is Two Pointer Approach?

Two Pointer is a technique where **two variables (pointers)** iterate over the data structure (usually array or string) from:

* Opposite ends (**left** and **right**) or
* Same direction (**i** and **j**, or slow/fast)

---

### 🔸 When to Use?

* **Sorted arrays** or strings
* **Searching** for a pair (sum, condition, palindrome, etc.)
* **Removing duplicates**
* **Reversing** (in-place)
* **Comparing strings/arrays**

---

## 📌 Example 1: **Check if Array has Pair with Given Sum**

**Input**: `arr = [1, 2, 3, 4, 6], target = 6`
**Output**: Yes → because `2 + 4 = 6`
**Note**: Array **must be sorted**

---

### ✅ C++ Code

```cpp
bool hasPairWithSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) return true;
        else if(sum < target) left++;
        else right--;
    }
    return false;
}
```

---

## 📌 Example 2: **Reverse an Array Using Two Pointers**

```cpp
void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        swap(arr[left++], arr[right--]);
    }
}
```

---

## 📌 Example 3: **Is Palindrome (String)**

```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while(left < right) {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
```

---

## 📌 Example 4: **Remove Duplicates From Sorted Array** (Leetcode 26)

```cpp
int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;

    int i = 0;
    for(int j = 1; j < nums.size(); j++) {
        if(nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
```

---

## 🔁 Patterns with Two Pointers

| Problem Type               | Examples                                 |
| -------------------------- | ---------------------------------------- |
| Find a pair with given sum | Sorted array or use HashMap for unsorted |
| Palindrome check           | Left ↔ Right comparison                  |
| Reverse array or string    | Swap with 2 pointers                     |
| Remove duplicates in-place | Sorted array – use slow & fast pointers  |
| Merge sorted arrays        | Classic two pointer merge                |
| Trapping rainwater         | Two pointer from both ends (Leetcode 42) |
| Container with most water  | Leetcode 11                              |

---

## 💡 Where Two Pointer Shines

* Reduces nested loops (`O(n²)`) to `O(n)`
* Especially useful on **sorted arrays**
* Ideal for **space optimization**

---

## ✅ Practice Problems (Highly Recommended):

| Problem                                | Link                                                                              |
| -------------------------------------- | --------------------------------------------------------------------------------- |
| 🟢 Two Sum II – Input Array Is Sorted  | [Leetcode 167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)   |
| 🟡 Remove Duplicates from Sorted Array | [Leetcode 26](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) |
| 🟢 Valid Palindrome                    | [Leetcode 125](https://leetcode.com/problems/valid-palindrome/)                   |
| 🟡 Container With Most Water           | [Leetcode 11](https://leetcode.com/problems/container-with-most-water/)           |
| 🔵 Trapping Rain Water                 | [Leetcode 42](https://leetcode.com/problems/trapping-rain-water/)                 |
