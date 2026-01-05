# MERGE SORT (Recursion Concept)

## 1. What is Merge Sort?

Merge Sort is a **divide and conquer** sorting algorithm.

Goal:

* Sort an array in **non-decreasing order**

Key idea:

* If an array is too big to sort directly,
  **break it into smaller parts**, sort them, then **merge** them.

---

## 2. Core Idea (Human Intuition)

> “I cannot sort a big array.
> I will divide it into two halves.
> You sort the left half, you sort the right half.
> I will only merge the two sorted halves.”

This “trust” is **recursion**.

---

## 3. Recursion Story (Very Important)

We write a function:

```
mergeSort(arr, l, r)
```

### Story inside the function:

1. **Base Case**

   * If `l >= r`
   * Only one element (or invalid range)
   * Already sorted → return

2. **Divide**

   * Find middle index

     ```
     mid = l + (r - l) / 2
     ```
   * Split array into:

     * Left: `l → mid`
     * Right: `mid+1 → r`

3. **Trust Recursion**

   * Ask recursion to sort both halves:

     ```
     mergeSort(arr, l, mid)
     mergeSort(arr, mid+1, r)
     ```

4. **Merge**

   * Merge the two sorted halves into one sorted range

That’s it.

---

## 4. Why Merge Works?

Because:

* Left half is already sorted
* Right half is already sorted

Merging two sorted arrays can be done in **linear time** using two pointers.

---

## 5. Merge Process (Two Pointer Logic)

Given:

* Left array `L`
* Right array `R`

Steps:

1. Pointer `i` for `L`
2. Pointer `j` for `R`
3. Pointer `k` for original array

At each step:

* Compare `L[i]` and `R[j]`
* Put smaller element in `arr[k]`
* Move pointers

If one array finishes:

* Copy remaining elements of the other array

---

## 6. Complete C++ Code (Clean + Commented)

```cpp
#include <iostream>
#include <vector>
using namespace std;

/*
Merge two sorted subarrays of arr:
Left  -> arr[l ... mid]
Right -> arr[mid+1 ... r]
*/
void merge(vector<int>& arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge temp arrays back into arr
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements (if any)
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

/*
Recursive Merge Sort
*/
void mergeSort(vector<int>& arr, int l, int r)
{
    // Base case: single element
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;

    // Sort left half
    mergeSort(arr, l, mid);

    // Sort right half
    mergeSort(arr, mid + 1, r);

    // Merge both halves
    merge(arr, l, mid, r);
}

int main()
{
    vector<int> arr = {3, 2, 1, 5};

    mergeSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}
```

---

## 7. Dry Run (Very Short)

Input:

```
[3, 2, 1, 5]
```

Steps:

```
Split → [3,2] [1,5]
Split → [3] [2] [1] [5]
Merge → [2,3] [1,5]
Merge → [1,2,3,5]
```

---

## 8. Time Complexity

* **Depth of recursion tree**: `log n`
* **Work at each level (merge)**: `n`

```
Time = O(n log n)
```

---

## 9. Space Complexity

* Temporary arrays during merge: `O(n)`
* Recursion stack: `O(log n)`

```
Space = O(n)
```

---

## 10. Key Interview Takeaways

* Merge Sort uses **Divide + Trust + Merge**
* Stable sorting algorithm
* Guaranteed `O(n log n)`
* Extra space required
* Very strong recursion example

---