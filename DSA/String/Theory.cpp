# Strings in C++ for DSA Preparation

## 1. What is a String?
A string is a sequence of characters stored contiguously in memory. In C++, strings can be represented as:
- C-style strings (null-terminated character arrays)
- `std::string` (STL container class, recommended for DSA)

### How Strings are Stored
- C-style strings: Array of `char` with `\0` (null terminator) at the end.
  ```
  char str[] = "hello"; // Memory: ['h','e','l','l','o','\0']
  ```
- `std::string`: Dynamic character array managed by STL (no manual null termination needed).

---

## 2. Basic STL for Strings (`<string>`)
```cpp
#include <string>
using namespace std;

string s = "Hello";
```
### Common String Operations
| Function | Description | Example |
|----------|-------------|---------|
| `s.length()` | Get string length | `s.length()` → 5 |
| `s.push_back(c)` | Append character | `s.push_back('!')` → "Hello!" |
| `s.pop_back()` | Remove last character | `s.pop_back()` → "Hell" |
| `s.substr(pos, len)` | Get substring | `s.substr(1, 3)` → "ell" |
| `s.find(str)` | Find substring | `s.find("ell")` → 1 |
| `s.erase(pos, len)` | Remove substring | `s.erase(1, 2)` → "Hlo" |
| `s.replace(pos, len, str)` | Replace substring | `s.replace(1, 2, "i")` → "Hilo" |

---

## 3. Different Ways to Declare Strings
### (a) C-style Strings
```cpp
char str1[] = "Hello"; // Stack allocation
char str2[10]; // Uninitialized (max 9 chars + '\0')
const char* str3 = "World"; // Read-only memory
```

### (b) STL String (`std::string`)
```cpp
string s1 = "Hello"; // Initialized
string s2(5, 'x'); // "xxxxx"
string s3(s1); // Copy of s1
```

---

## 4. Dynamic Allocation for Strings
### (a) C-style (Heap)
```cpp
char* str = new char[20]; // Allocate
strcpy(str, "Dynamic"); // Assign
delete[] str; // Deallocate
```

### (b) STL String (Automatic Management)
```cpp
string* s = new string("Hello");
delete s; // Rarely needed (prefer stack allocation)
```

---

## 5. Example Problem with Solution
### Problem: Reverse a String
```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseString(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        swap(s[left++], s[right--]);
    }
    return s;
}

int main() {
    string s = "hello";
    cout << reverseString(s) << endl; // "olleh"
    return 0;
}
```
Alternate STL Solution:
```cpp
reverse(s.begin(), s.end());
```

---

## 6. Three Practice Problems
### Easy: Check Palindrome
Determine if a string reads the same backward (e.g., "madam").
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}
```

### Medium: Longest Substring Without Repeating Characters
Given "abcabcbb", the answer is "abc" (length 3).
```cpp
int lengthOfLongestSubstring(string s) {
    vector<int> map(128, -1); // Stores last index of each char
    int start = -1, max_len = 0;
    for (int i = 0; i < s.size(); i++) {
        if (map[s[i]] > start) start = map[s[i]];
        map[s[i]] = i;
        max_len = max(max_len, i - start);
    }
    return max_len;
}
```

### Hard: Minimum Window Substring
Given `s = "ADOBECODEBANC"` and `t = "ABC"`, return "BANC".
```cpp
string minWindow(string s, string t) {
    vector<int> freq(128, 0);
    for (char c : t) freq[c]++;
    int left = 0, right = 0, min_len = INT_MAX, start = 0, count = t.size();
    while (right < s.size()) {
        if (freq[s[right++]]-- > 0) count--;
        while (count == 0) {
            if (right - left < min_len) {
                min_len = right - left;
                start = left;
            }
            if (freq[s[left++]]++ == 0) count++;
        }
    }
    return min_len == INT_MAX ? "" : s.substr(start, min_len);
}
```

---

## Key Takeaways
✅ Prefer `std::string` over C-strings for DSA (safer, more functions).  
✅ STL functions (`reverse`, `substr`, `find`) simplify coding.  
✅ Sliding window is a common pattern for substring problems.  

Ready for more string problems or specific explanations? 😊