## 🔶 1. **What is Bit Manipulation?**

Bit manipulation is the process of **directly operating on individual bits** of integers using **bitwise operators**. It allows efficient coding, especially when you’re dealing with **binary numbers**, **sets**, **bitmasks**, etc.

All integers are stored in **binary form**, so bit manipulation gives you fine-grained control over how data is handled.

---

## 🔶 2. **Bitwise Operators**

| Operator    | Symbol | Meaning                 | Example (a=5, b=3)            |     |              |            |
| ----------- | ------ | ----------------------- | ----------------------------- | --- | ------------ | ---------- |
| AND         | `&`    | 1 if both bits are 1    | `5 & 3 = 1` (101 & 011 = 001) |     |              |            |
| OR          | \`     | \`                      | 1 if any bit is 1             | \`5 | 3 = 7\` (101 | 011 = 111) |
| XOR         | `^`    | 1 if bits are different | `5 ^ 3 = 6` (101 ^ 011 = 110) |     |              |            |
| NOT         | `~`    | Inverts bits            | `~5 = -6` (2’s complement)    |     |              |            |
| Left Shift  | `<<`   | Shifts bits left        | `5 << 1 = 10` (101 → 1010)    |     |              |            |
| Right Shift | `>>`   | Shifts bits right       | `5 >> 1 = 2` (101 → 10)       |     |              |            |

---

## 🔶 3. **Binary Representation**

* **Decimal to Binary**: `5` → `0101`
* **Negative Numbers**: Use **2’s complement**.

  * `~x = -x - 1`
  * Example: `~5 = -6`

---

## 🔶 4. **Common Bit Tricks (Must Know)**

### ✅ Check if a number is even or odd:

```cpp
if (n & 1) cout << "Odd"; else cout << "Even";
```

### ✅ Multiply or divide by 2:

```cpp
n << 1  // Multiply by 2
n >> 1  // Divide by 2
```

### ✅ Swap two numbers without temp:

```cpp
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

### ✅ Set i-th bit:

```cpp
n | (1 << i)
```

### ✅ Clear i-th bit:

```cpp
n & ~(1 << i)
```

### ✅ Toggle i-th bit:

```cpp
n ^ (1 << i)
```

### ✅ Check i-th bit is set:

```cpp
(n & (1 << i)) != 0
```

### ✅ Count set bits (Brian Kernighan's Algo):

```cpp
int count = 0;
while (n) {
    n &= (n - 1);
    count++;
}
```

### ✅ Check power of 2:

```cpp
if (n > 0 && (n & (n - 1)) == 0)
```

---

## 🔶 5. **Bitmasking (Advanced Concept)**

Used to represent **sets** of numbers using bits.

Example: Set of numbers `{1, 3, 4}` from 1 to 5 → `11010`
(bit\[1]=1, bit\[3]=1, bit\[4]=1)

Operations:

* Add: `mask |= (1 << i)`
* Remove: `mask &= ~(1 << i)`
* Check: `mask & (1 << i)`

---

## 🔶 6. **STL Functions for Bit Manipulation (C++)**

You can use `<bitset>` for easy bit manipulation.

```cpp
#include <bitset>

bitset<8> b(5); // 00000101
b.set(2);       // 00000101 -> 00000111
b.flip(0);      // 00000111 -> 00000110
b.count();      // Number of 1s
b.test(2);      // Check if bit at index 2 is set
```

---

## 🔶 7. **Visualization**

Let’s visualize 5 (`0101`) and 3 (`0011`) bit-by-bit:

```
   0101   (5)
&  0011   (3)
=  0001   (1)

|  0111   (7)
^  0110   (6)
```

Use **truth tables** to understand:

\| a | b | a\&b | a|b | a^b |
\|---|---|-----|-----|-----|
\| 0 | 0 |  0  |  0  |  0  |
\| 0 | 1 |  0  |  1  |  1  |
\| 1 | 0 |  0  |  1  |  1  |
\| 1 | 1 |  1  |  1  |  0  |

---

## 🔶 8. **3 Coding Questions**

### ✅ Q1: Count the number of 1's in binary representation (set bits)

**Input:** `n = 13` → `1101` → Output: `3`

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
```

---

### ✅ Q2: Check if a number is a power of two

**Input:** `n = 8` → Output: `true` (since 8 is 2^3)

```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

---

### ✅ Q3: Find the only non-repeating element (All other elements appear twice)

**Input:** `arr = [2, 3, 5, 3, 2]` → Output: `5`

```cpp
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
        ans ^= num;
    }
    return ans;
}
```

---

## ✅ Summary

* Bit manipulation is about efficient handling of binary data.
* Master basic operations (`&, |, ^, ~, <<, >>`)
* Learn tricks like setting, clearing, toggling bits.
* Use bitmasking for subset, DP, and optimization problems.
* Practice is key to mastering this topic.
---
You're absolutely right to question this — and this is where **bit manipulation concepts meet mathematical limitations**.

Let’s break this down thoroughly:

---

## 🔶 Expression: `n >> 1` means "Right shift by 1 bit"

It is **not exactly** the same as dividing by 2 in all cases, though it's **mathematically similar** for **positive integers**.

---

## ✅ Let's analyze `n = 7`

### Binary of 7:

```
7  = 111 (binary)
7 >> 1 = 011 (binary) = 3 (decimal)
```

So, you were correct:

```
111 >> 1 → 011 → 3
```

---

## ✅ Now let’s talk about this statement:

> “3 cannot be divided by 2”

This needs a **clarification**:

* **Integer Division** in C++ and most languages **truncates the decimal**.
* So `3 / 2 = 1` in integer division.
* But `3.0 / 2 = 1.5` in floating point division.

Now, compare that with:

```cpp
n = 7;
int half = n >> 1; // half = 3
```

and

```cpp
int half = n / 2; // also 3
```

So:
📌 `n >> 1` is **equivalent to integer division by 2**, **not floating point division**.

---

## 🔍 What’s the catch?

* **Right shift (`>> 1`) removes the last bit** of a binary number.
* This is **like dividing by 2 and taking the floor**.

Let’s look at a few examples:

| `n` | Binary | `n >> 1` | Decimal Value | `n / 2` (int) |
| --- | ------ | -------- | ------------- | ------------- |
| 6   | 110    | 011      | 3             | 3             |
| 7   | 111    | 011      | 3             | 3             |
| 8   | 1000   | 0100     | 4             | 4             |
| 9   | 1001   | 0100     | 4             | 4             |

So `n >> 1` and `n / 2` **match perfectly** for **positive integers**.

---

## ❗ But what about negatives?

This is where the difference starts showing:

### C++ Right Shift Behavior:

* Right shift of **negative numbers** is **implementation-defined** (depends on compiler).
* On most modern compilers (GCC, Clang), it performs **arithmetic shift**:

  * Preserves the sign bit (most significant bit).
  * So `-3 >> 1 = -2` (because `-3 / 2 = -1` but shifting keeps sign).

---

## ✅ Conclusion

| Operation            | Result                                                 | Meaning                       |
| -------------------- | ------------------------------------------------------ | ----------------------------- |
| `n >> 1`             | Same as `n / 2` (integer)                              | Removes least significant bit |
| Works accurately for | **Positive integers**                                  |                               |
| Different from `/2`  | Only for **negative integers** or **non-integer math** |                               |

---

## ❓ Your doubt was valid:

> "3 cannot be divided by 2" — correct, **3 cannot be exactly divided** by 2 **into an integer**, but bit manipulation follows the **floor of division** logic.

So:

```cpp
7 / 2 = 3        // Integer division
7 >> 1 = 3       // Right shift
```

They match.

---
✅ Yes — you're **absolutely right!** Let’s confirm both of your statements clearly:

---

## ✅ 1. `7 >> 1` is like `7 / 2` (integer division)

```cpp
7 >> 1  → 011  (binary) → 3 (decimal)
7 / 2   → 3    (integer division, decimal ignored)
```

✔️ So: `7 >> 1 == 7 / 2` ✅

---

## ✅ 2. `3 << 1` is like `3 * 2`

```cpp
3 = 011 (binary)
3 << 1 = 110 (binary) = 6
```

✔️ So: `3 << 1 == 3 * 2` ✅

---

### 🔁 General Rules

| Operation | Equivalent To   | Example       |
| --------- | --------------- | ------------- |
| `n << 1`  | `n * 2`         | `5 << 1 = 10` |
| `n << k`  | `n * 2^k`       | `3 << 3 = 24` |
| `n >> 1`  | `n / 2` (int)   | `7 >> 1 = 3`  |
| `n >> k`  | `n / 2^k` (int) | `16 >> 2 = 4` |

✅ **Only for positive integers.** For negative numbers, behavior of `>>` can differ depending on the compiler (sign-extension vs logical shift).

---

## 🚀 Summary:

* `7 >> 1 == 3` → ✅ yes, same as integer division.
* `3 << 1 == 6` → ✅ yes, same as multiplying by 2.
* `n << k = n * 2^k`
* `n >> k = floor(n / 2^k)`