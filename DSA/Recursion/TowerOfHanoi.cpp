# **Detailed Explanation of the Tower of Hanoi Recursive Solution**

The Tower of Hanoi is a classic mathematical puzzle that demonstrates the power of recursion beautifully. Let's break down the solution step by step.

## **Problem Statement**
- **Given**: 3 rods (source 'A', destination 'C', auxiliary 'B') and `n` disks of different sizes on the source rod
- **Rules**:
  1. Only one disk can be moved at a time
  2. A larger disk cannot be placed on top of a smaller disk
- **Goal**: Move all disks from source to destination rod

## **Recursive Solution Breakdown**

```cpp
void towerOfHanoi(int n, char from, char to, char aux) {
    // Base case: Only 1 disk to move
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    
    // Step 1: Move top n-1 disks from source to auxiliary rod
    towerOfHanoi(n - 1, from, aux, to);
    
    // Step 2: Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    
    // Step 3: Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, aux, to, from);
}
```

## **Step-by-Step Execution for n=3 Disks**

### **Initial State**
```
A: [3, 2, 1] (1 is top, 3 is bottom)
B: []
C: []
```

### **1. First Call: towerOfHanoi(3, 'A', 'C', 'B')**
- Not base case (n=3)
- **Recursive Step 1**: Move 2 disks from A to B using C as auxiliary
  ```cpp
  towerOfHanoi(2, 'A', 'B', 'C');
  ```

### **2. Second Call: towerOfHanoi(2, 'A', 'B', 'C')**
- Not base case (n=2)
- **Recursive Step 1**: Move 1 disk from A to C using B as auxiliary
  ```cpp
  towerOfHanoi(1, 'A', 'C', 'B'); // Base case hit!
  ```
  - **Output**: `Move disk 1 from A to C`
  
- **Current State**:
  ```
  A: [3, 2]
  B: []
  C: [1]
  ```

- **Move disk 2**:
  ```cpp
  cout << "Move disk 2 from A to B" << endl;
  ```
  - **Output**: `Move disk 2 from A to B`
  
- **Recursive Step 3**: Move 1 disk from C to B using A as auxiliary
  ```cpp
  towerOfHanoi(1, 'C', 'B', 'A'); // Base case hit!
  ```
  - **Output**: `Move disk 1 from C to B`

- **Current State**:
  ```
  A: [3]
  B: [2, 1]
  C: []
  ```

### **3. Back to First Call**
- Now move the largest disk (3) from A to C
```cpp
cout << "Move disk 3 from A to C" << endl;
```
- **Output**: `Move disk 3 from A to C`

- **Current State**:
```
A: []
B: [2, 1]
C: [3]
```

### **4. Final Recursive Step**
- Move 2 disks from B to C using A as auxiliary
```cpp
towerOfHanoi(2, 'B', 'C', 'A');
```

### **5. Third Call: towerOfHanoi(2, 'B', 'C', 'A')**
- Not base case (n=2)
- **Recursive Step 1**: Move 1 disk from B to A using C as auxiliary
  ```cpp
  towerOfHanoi(1, 'B', 'A', 'C'); // Base case hit!
  ```
  - **Output**: `Move disk 1 from B to A`
  
- **Current State**:
  ```
  A: [1]
  B: [2]
  C: [3]
  ```

- **Move disk 2**:
  ```cpp
  cout << "Move disk 2 from B to C" << endl;
  ```
  - **Output**: `Move disk 2 from B to C`
  
- **Recursive Step 3**: Move 1 disk from A to C using B as auxiliary
  ```cpp
  towerOfHanoi(1, 'A', 'C', 'B'); // Base case hit!
  ```
  - **Output**: `Move disk 1 from A to C`

### **Final State**
```
A: []
B: []
C: [3, 2, 1]
```

## **Complete Output for n=3**
```
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```

## **Key Insights**
1. **Recursive Pattern**:
   - Move `n-1` disks from source to auxiliary
   - Move the nth disk from source to destination
   - Move `n-1` disks from auxiliary to destination

2. **Time Complexity**: O(2ⁿ) since each call generates 2 more calls

3. **Space Complexity**: O(n) for the call stack depth

4. **Minimum Moves**: Always requires 2ⁿ - 1 moves for n disks

This recursive approach elegantly breaks down the problem into identical subproblems, demonstrating the power of recursion in solving complex problems with simple code.