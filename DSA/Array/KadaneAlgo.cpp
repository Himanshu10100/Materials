# **Kadane's Algorithm Explained (with Example & C++ Code)**

Kadane's Algorithm is an efficient **O(n)** solution to find the **maximum subarray sum** in a given array of numbers (including negative values).

## **Key Idea**
- Iterate through the array while maintaining:
  - `current_sum` = Maximum subarray sum ending at the current position.
  - `max_sum` = Overall maximum subarray sum found so far.
- If `current_sum` becomes negative, reset it to `0` (since a negative sum will only reduce future sums).

---

## **Example Walkthrough**
**Input Array:** `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`

| Step | Element | `current_sum` (before update) | `current_sum` (after update) | `max_sum` |
|------|---------|-------------------------------|------------------------------|-----------|
| 1    | `-2`    | `0 + (-2) = -2`                | `max(-2, 0) = 0` (reset)      | `0`       |
| 2    | `1`     | `0 + 1 = 1`                    | `max(1, 0) = 1`              | `1`       |
| 3    | `-3`    | `1 + (-3) = -2`                | `max(-2, 0) = 0` (reset)      | `1`       |
| 4    | `4`     | `0 + 4 = 4`                    | `max(4, 0) = 4`              | `4`       |
| 5    | `-1`    | `4 + (-1) = 3`                 | `max(3, 0) = 3`              | `4`       |
| 6    | `2`     | `3 + 2 = 5`                    | `max(5, 0) = 5`              | `5`       |
| 7    | `1`     | `5 + 1 = 6`                    | `max(6, 0) = 6`              | `6`       |
| 8    | `-5`    | `6 + (-5) = 1`                 | `max(1, 0) = 1`              | `6`       |
| 9    | `4`     | `1 + 4 = 5`                    | `max(5, 0) = 5`              | `6`       |

**Final Answer:** `6` (from subarray `[4, -1, 2, 1]`).

---

## **C++ Implementation**
### **1. Basic Kadane's Algorithm (Returns Maximum Sum)**
```cpp
#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

int kadane(vector<int>& nums) {
    int current_sum = 0;
    int max_sum = INT_MIN; // Handles all-negative arrays
    
    for (int num : nums) {
        current_sum += num;
        max_sum = max(max_sum, current_sum);
        if (current_sum < 0) {
            current_sum = 0; // Reset if negative
        }
    }
    return max_sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << kadane(nums) << endl;
    return 0;
}
```
**Output:**
```
Maximum Subarray Sum: 6
```

---

### **2. Extended Version (Returns Subarray Indices)**
```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void kadaneWithIndices(vector<int>& nums) {
    int current_sum = 0;
    int max_sum = INT_MIN;
    int start = 0, end = 0;
    int temp_start = 0; // Tracks the start of the current subarray

    for (int i = 0; i < nums.size(); i++) {
        current_sum += nums[i];
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
        
        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1; // Reset start position
        }
    }

    cout << "Maximum Sum: " << max_sum << endl;
    cout << "Subarray: [";
    for (int i = start; i <= end; i++) {
        cout << nums[i] << (i < end ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    kadaneWithIndices(nums);
    return 0;
}
```
**Output:**
```
Maximum Sum: 6
Subarray: [4, -1, 2, 1]
```

---

## **Time & Space Complexity**
- **Time Complexity:** **O(n)** (Single pass through the array).  
- **Space Complexity:** **O(1)** (No extra space used).  

---

## **Practice Problems**
1. **All-Negative Array:**  
   Input: `[-3, -1, -2]` → Output: `-1` (from `[-1]`).  
2. **Single Element:**  
   Input: `[5]` → Output: `5`.  
3. **Circular Subarray (Extension):**  
   Find the maximum subarray sum in a circular array (Hint: Use Kadane twice).

---

### **Key Takeaways**
✅ Works for **all-negative numbers** (unlike sliding window).  
✅ **Reset `current_sum` to 0** if it goes negative.  
✅ **Efficient O(n) solution** (better than brute-force O(n²)).  

Let me know if you'd like more variations or explanations! 😊