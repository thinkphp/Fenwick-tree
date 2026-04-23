## Fenwick Tree or Binary Indexed Tree Data Structure

Fenwick Tree is a data structure that was described in a paper by Peter M. Feniwick in 1994. It is useful for efficiently calculating sums and updating element values in an array.

## 📌 Overview

The **Fenwick Tree** (also known as **Binary Indexed Tree - BIT**) is a data structure that efficiently supports:

- prefix sum queries
- point updates

All operations run in **O(log n)** time.

---

## 🚀 Supported Operations

| Operation            | Time Complexity |
|---------------------|-----------------|
| Update (add value)  | O(log n)        |
| Query (prefix sum)  | O(log n)        |
| Range sum query     | O(log n)        |

---

## 🧠 Core Idea

A Fenwick Tree stores partial sums in a way that:

- each index covers a range of size `2^k`
- navigation is done using the operation:

```cpp
i & (-i)
````

---

## 📦 C++ Implementation

```cpp
#include <iostream>
using namespace std;

int n;
int BIT[100] = {0};

void update(int i, int val) {
    while (i <= n) {
        BIT[i] += val;
        i += (i & -i);
    }
}

int query(int i) {
    int sum = 0;
    while (i >= 1) {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

int range_sum(int l, int r) {
    return query(r) - query(l - 1);
}
```

---

## 🔢 Example

```cpp
int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
n = 10;

for(int i = 1; i <= n; i++) {
    update(i, arr[i]);
}

cout << range_sum(2, 7); // Output: 27
```

---

## 📐 Key Formulas

* Prefix sum:

```
sum(1, x) = query(x)
```

* Range sum:

```
sum(l, r) = query(r) - query(l - 1)
```

---

## ⚙️ How `i & (-i)` Works

This operation extracts the **least significant set bit (LSB)**.

Examples:

| i (binary) | i & -i |
| ---------- | ------ |
| 6 (110)    | 2      |
| 8 (1000)   | 8      |
| 10 (1010)  | 2      |

---

## 📈 Advantages

* easy to implement
* memory efficient: O(n)
* fast updates and queries

---

## ⚠️ Limitations

* not suitable for complex operations (like min/max without modifications)
* less flexible than Segment Tree

---

## 🧩 Extensions

* Range Update + Point Query
* Range Update + Range Query (using 2 Fenwick Trees)
* Order statistics (finding k-th element)

---

## 🎯 When to Use

Use Fenwick Tree when:

* you need frequent updates
* you need fast range sum queries
* the data is dynamic

---

## 📚 Conclusion

Fenwick Tree is a powerful and efficient data structure for:

* range sum queries
* dynamic updates

It is simpler than a Segment Tree and performs very well in practice.


### Problem Set

- https://infoarena.ro/problema/aib
- https://cses.fi/problemset/task/1646/

### References:

https://www.hackerearth.com/practice/notes/binary-indexed-tree-or-fenwick-tree/

https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

https://cp-algorithms.com/data_structures/fenwick.html

https://sites.google.com/site/centrulinfo1/materiale-video/algoritmi-video/arbori-indexati-binar

https://www.enjoyalgorithms.com/blog/binary-indexed-tree

https://ideone.com/5Rlvmp
