# Binary Search in C++ for DSA Preparation

## 1. What is Binary Search?
Binary search is an efficient O(log n) algorithm to find an element in a sorted array by repeatedly dividing the search interval in half.

### Key Properties
- Works only on sorted data (ascending/descending order)
- Divide and conquer approach
- Much faster than linear search (O(n)) for large datasets

## 2. How Binary Search Works
1. Compare target with the middle element
2. If target matches, return index
3. If target is smaller, search left half
4. If target is larger, search right half
5. Repeat until found or search space is exhausted

```mermaid
graph TD
    A[Start with full array] --> B{Compare target to middle}
    B -->|Equal| C[Return index]
    B -->|Target < Middle| D[Search left half]
    B -->|Target > Middle| E[Search right half]
    D --> B
    E --> B
```

## 3. Basic Implementation (Iterative)
```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Not found
}
```

## 4. Common Variations

### a) First Occurrence of Element
```cpp
int firstOccurrence(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            result = mid;
            right = mid - 1; // Continue searching left
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

### b) Last Occurrence of Element
```cpp
int lastOccurrence(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            result = mid;
            left = mid + 1; // Continue searching right
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

### c) Ceiling of a Number
```cpp
int ceiling(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left < nums.size() ? left : -1; // Next greater element
}
```

## 5. Example Problem with Solution

### Problem: Search in Rotated Sorted Array
Given a rotated sorted array like `[4,5,6,7,0,1,2]`, find the index of `target = 0`.

```cpp
int searchRotated(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) return mid;
        
        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}
```

## 6. Three Practice Problems

### Easy: Square Root (Floor Value)
Find floor of square root of a number without using `sqrt()`.
```cpp
int sqrt(int x) {
    if (x < 2) return x;
    
    int left = 1, right = x/2;
    int result = 0;
    
    while (left <= right) {
        long mid = left + (right - left)/2;
        long square = mid * mid;
        
        if (square == x) return mid;
        else if (square < x) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

### Medium: Find Peak Element
A peak element is greater than its neighbors.
```cpp
int findPeak(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left)/2;
        
        if (nums[mid] < nums[mid+1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}
```

### Hard: Median of Two Sorted Arrays
Find median of two sorted arrays in O(log(min(m,n))).
```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int x = nums1.size(), y = nums2.size();
    int low = 0, high = x;
    
    while (low <= high) {
        int partitionX = (low + high)/2;
        int partitionY = (x + y + 1)/2 - partitionX;
        
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
        
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
        
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                return max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    
    return 0.0;
}
```

## Key Takeaways
✅ Always verify if input is sorted before applying binary search  
✅ Use `mid = left + (right - left)/2` to avoid overflow  
✅ For rotated arrays, identify the sorted half first  
✅ Practice variations (first/last occurrence, ceiling/floor)  

Would you like more problems or specific explanations? 😊