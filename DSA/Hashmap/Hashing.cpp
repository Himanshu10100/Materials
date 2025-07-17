## ✅ Topic: **Hashing (C++)**

---

### 🔹 What is Hashing?

Hashing is a technique used to **map data to a fixed-size table** using a **hash function**.
In C++, we use containers like:

* `unordered_map` → key-value store
* `unordered_set` → store unique elements
* `map` → ordered key-value
* `set` → ordered unique elements

---

### 🧠 Why Use Hashing?

* **Fast lookup**: `O(1)` average time for insert/find/delete (unordered\_map)
* **Avoid nested loops** (e.g., find duplicates, count frequency)
* **Track presence, frequency, index of elements**

---

## 🔸 Key STL Hashing Containers in C++

| Container               | Description                               |
| ----------------------- | ----------------------------------------- |
| `unordered_map`         | Fast, not sorted, key-value store         |
| `unordered_set`         | Fast, not sorted, unique values           |
| `map`                   | Sorted by key, slower than unordered\_map |
| `set`                   | Sorted unique values                      |
| `multimap` / `multiset` | Allow duplicates                          |

---

## 🔹 Example 1: **Count Frequency of Each Element**

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void countFrequency(vector<int>& nums) {
    unordered_map<int, int> freq;

    for (int num : nums)
        freq[num]++;

    for (auto it : freq)
        cout << it.first << " appears " << it.second << " times\n";
}
```

---

## 🔹 Example 2: **First Non-Repeating Character in String**

```cpp
char firstUniqueChar(string s) {
    unordered_map<char, int> count;

    for (char c : s)
        count[c]++;

    for (char c : s)
        if (count[c] == 1)
            return c;

    return '_'; // if no unique character
}
```

---

## 🔹 Example 3: **Find Duplicates in Array**

```cpp
bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}
```

---

## 🔹 Example 4: **Two Sum Using HashMap**

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < nums.size(); i++) {
        int rem = target - nums[i];
        if (mp.count(rem))
            return {mp[rem], i};
        mp[nums[i]] = i;
    }
    return {};
}
```

---

## 🧩 Hashing Patterns in Problems

| Problem Type             | Concept                  |
| ------------------------ | ------------------------ |
| Frequency counting       | map or unordered\_map    |
| Detect duplicates        | set or unordered\_set    |
| Hash-based search        | key existence in map/set |
| Grouping anagrams        | hash + sorting           |
| Sliding window + hash    | count/track characters   |
| Subarrays with given sum | prefix sum + map         |

---

## 🟦 Hash Function Example

```cpp
#include <functional>
#include <iostream>
using namespace std;

int main() {
    hash<string> myHash;
    cout << "Hash of 'chatgpt': " << myHash("chatgpt") << endl;
}
```

---

## ✅ 3 Coding Questions to Practice

1. 🔵 **Find All Duplicates in an Array**
   [Leetcode 442](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

2. 🟡 **Group Anagrams**
   [Leetcode 49](https://leetcode.com/problems/group-anagrams/)

3. 🔵 **Longest Substring Without Repeating Characters**
   [Leetcode 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
