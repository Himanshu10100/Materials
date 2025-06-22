# Recursion in C++ for DSA Preparation

## 1. What is Recursion?
Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem. It consists of:
- Base case(s): Simple, non-recursive solution
- Recursive case(s): Function calls itself with a smaller input

### Key Properties
- Works by breaking problems into smaller subproblems
- Uses the call stack to manage function calls
- Can often be replaced with iteration (but recursion is cleaner for some problems)

## 2. How Recursion Works
```mermaid
graph TD
    A[Initial Call] --> B{Base Case?}
    B -->|Yes| C[Return Simple Value]
    B -->|No| D[Break Problem Down]
    D --> E[Recursive Call]
    E --> B
```

## 3. Basic Implementation (Factorial Example)
```cpp
int factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}
```

## 4. Common Recursion Patterns

### a) Head Recursion
Processing happens after the recursive call
```cpp
void printCountDown(int n) {
    if (n == 0) return; // Base case
    printCountDown(n - 1); // Recursive call first
    cout << n << " "; // Processing after
}
// Input: 5 → Output: "1 2 3 4 5"
```

### b) Tail Recursion
Processing happens before the recursive call (can be optimized to iteration)
```cpp
void printCountUp(int n) {
    if (n == 0) return; // Base case
    cout << n << " "; // Processing first
    printCountUp(n - 1); // Recursive call after
}
// Input: 5 → Output: "5 4 3 2 1"
```

### c) Tree Recursion
Multiple recursive calls from one function
```cpp
int fibonacci(int n) {
    if (n <= 1) return n; // Base case
    return fibonacci(n - 1) + fibonacci(n - 2); // Two recursive calls
}
```

## 5. Example Problem with Solution

### Problem: Reverse a String Using Recursion
```cpp
void reverseString(string &s, int left, int right) {
    // Base case
    if (left >= right) return;
    
    // Process current pair
    swap(s[left], s[right]);
    
    // Recursive call
    reverseString(s, left + 1, right - 1);
}

// Usage:
string s = "hello";
reverseString(s, 0, s.length() - 1);
// s becomes "olleh"
```

## 6. Three Practice Problems

### Easy: Sum of Digits
Calculate sum of digits recursively.
```cpp
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}
// sumOfDigits(123) → 6
```

### Medium: Tower of Hanoi
Solve the classic puzzle with recursion.
```cpp
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}
// towerOfHanoi(3, 'A', 'C', 'B')
```

### Hard: Generate All Permutations
Print all permutations of a string.
```cpp
void permute(string s, int l, int r) {
    if (l == r) {
        cout << s << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l + 1, r);
            swap(s[l], s[i]); // Backtrack
        }
    }
}
// permute("ABC", 0, 2)
```

## 7. Recursion vs Iteration

| Aspect | Recursion | Iteration |
|--------|-----------|-----------|
| Code Length | Shorter, cleaner | Longer |
| Memory Usage | More (call stack) | Less |
| Speed | Slower (function call overhead) | Faster |
| Problem Suitability | Tree/graph problems, divide-and-conquer | Simple loops, linear processing |

## 8. Key Optimization Techniques

1. Memoization: Store results of expensive function calls
```cpp
unordered_map<int, int> memo;
int fib(int n) {
    if (n <= 1) return n;
    if (memo.find(n) != memo.end()) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
```

2. Tail Call Optimization: Compilers can optimize tail recursion to iteration

## 9. When to Use Recursion
- Problems with recursive structure (trees, graphs)
- Divide and conquer algorithms (merge sort, quick sort)
- Backtracking problems (permutations, combinations)
- When code simplicity is more important than performance

## 10. Common Pitfalls
1. No base case → Infinite recursion → Stack overflow
2. Not changing state → Infinite recursion
3. Too deep recursion → Stack overflow (use iteration instead)
4. Recomputing values → Use memoization

Would you like more examples or explanations on any specific recursion topic? 😊