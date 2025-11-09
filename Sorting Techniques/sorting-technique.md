# Sorting Techniques

## **Topic: Selection Sort Algorithm**

### **Concept**

Selection Sort is a **comparison-based, in-place sorting algorithm**.

**Logic step-by-step:**

1. Divide the array into two parts — **sorted** (left) and **unsorted** (right).
2. Initially, the **sorted part is empty**, and the entire array is unsorted.
3. In each iteration:

   * Find the **minimum element** in the unsorted part.
   * Swap it with the **first element of the unsorted part**.
4. After each pass, the boundary between sorted and unsorted moves one step right.

---

### **Example**

**Input:**
`arr = [13, 46, 24, 52, 20, 9]`

**Step-by-step dry run:**

| Pass | Unsorted Range     | Min Element | Swap Positions | Array After Pass   |
| ---- | ------------------ | ----------- | -------------- | ------------------ |
| 1    | [13,46,24,52,20,9] | 9           | swap(0,5)      | [9,46,24,52,20,13] |
| 2    | [46,24,52,20,13]   | 13          | swap(1,5)      | [9,13,24,52,20,46] |
| 3    | [24,52,20,46]      | 20          | swap(2,4)      | [9,13,20,52,24,46] |
| 4    | [52,24,46]         | 24          | swap(3,4)      | [9,13,20,24,52,46] |
| 5    | [52,46]            | 46          | swap(4,5)      | [9,13,20,24,46,52] |

**Final Sorted Array:** `[9,13,20,24,46,52]`

---

### **Code (C++)**

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to perform Selection Sort
void selection_sort(int arr[], int n) {
    
    // Outer loop runs (n - 1) times
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // assume current index has smallest value

        // Inner loop to find the actual minimum in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // update if smaller element found
            }
        }

        // Swap the found minimum element with the element at index 'i'
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Selection Sort:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    selection_sort(arr, n);

    cout << "After Selection Sort:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
```

---

### **Output**

```
Before Selection Sort:
13 46 24 52 20 9
After Selection Sort:
9 13 20 24 46 52
```

---

### **Complexity Analysis**

| Case    | Time Complexity | Reason                                      |
| ------- | --------------- | ------------------------------------------- |
| Best    | O(N²)           | No early termination — all comparisons done |
| Average | O(N²)           | Nested loops always run same                |
| Worst   | O(N²)           | Same as best                                |
| Space   | O(1)            | Sorting is in-place (no extra array)        |

---

### **Notes**

* **Stable?** ❌ No, Selection Sort is not stable (can change relative order of equal elements).
* **Adaptive?** ❌ No, even if already sorted, it still does O(N²) work.
* **When to use?**

  * For small arrays
  * When memory is tight (no extra space needed)
  * In teaching environments for understanding basic sorting mechanics

---

## **Topic: Bubble Sort Algorithm**

### **Concept**

Bubble Sort is a **comparison-based**, **in-place**, and **stable** sorting algorithm.

It works by **repeatedly swapping adjacent elements** if they are in the wrong order.
With each pass, the **largest element “bubbles up”** to its correct position at the end of the array.

---

### **How It Works (Step-by-Step)**

1. Start from the beginning of the array.
2. Compare each adjacent pair (`arr[j]` and `arr[j+1]`).
3. If `arr[j] > arr[j+1]`, **swap them**.
4. After one full pass, the **largest element** moves to the end.
5. Repeat the same process for the remaining unsorted part.
6. Continue until no swaps are required (array becomes sorted).

---

### **Example**

**Input:**
`arr = [13, 46, 24, 52, 20, 9]`

| Pass | Comparisons Made           | Swaps Done   | Array After Pass        |
| ---- | -------------------------- | ------------ | ----------------------- |
| 1    | Compare each pair till end | Many         | [13, 24, 46, 20, 9, 52] |
| 2    | Compare till index 4       | Swaps happen | [13, 24, 20, 9, 46, 52] |
| 3    | Compare till index 3       | Swaps happen | [13, 20, 9, 24, 46, 52] |
| 4    | Compare till index 2       | Swaps happen | [13, 9, 20, 24, 46, 52] |
| 5    | Compare till index 1       | Swaps happen | [9, 13, 20, 24, 46, 52] |

**Final Sorted Array:** `[9, 13, 20, 24, 46, 52]`

---

### **Code (C++ — Basic Version)**

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to perform Bubble Sort
void bubble_sort(int arr[], int n) {
    // Outer loop for number of passes
    for (int i = n - 1; i >= 0; i--) {
        // Inner loop for adjacent comparisons
        for (int j = 0; j <= i - 1; j++) {
            // If elements are in wrong order, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "After Bubble Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Bubble Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    bubble_sort(arr, n);

    return 0;
}
```

---

### **Output**

```
Before Bubble Sort:
13 46 24 52 20 9
After Bubble Sort:
9 13 20 24 46 52
```

---

### **Optimized Version (Best Case: O(N))**

If the array is already sorted, we can **avoid unnecessary passes** by using a flag to track whether any swap occurred.

**Logic:**

* If no swap happens in one full pass → array is sorted → break early.

---

### **Code (Optimized Bubble Sort)**

```cpp
#include <bits/stdc++.h>
using namespace std;

// Optimized Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0;  // flag to check if swap occurred

        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap adjacent elements
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;

                didSwap = 1;  // mark that a swap happened
            }
        }

        // if no swap happened, break early (array is sorted)
        if (didSwap == 0) break;
    }

    cout << "After Bubble Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Bubble Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    bubble_sort(arr, n);

    return 0;
}
```

---

### **Output**

```
Before Bubble Sort:
13 46 24 52 20 9
After Bubble Sort:
9 13 20 24 46 52
```

---

### **Time & Space Complexity**

| Case    | Time Complexity | Explanation                      |
| ------- | --------------- | -------------------------------- |
| Best    | **O(N)**        | No swaps needed (already sorted) |
| Average | **O(N²)**       | Normal unsorted case             |
| Worst   | **O(N²)**       | Reverse sorted array             |
| Space   | **O(1)**        | In-place sorting                 |

---

### **Notes**

* **Stable:** ✅ Yes, order of equal elements is preserved.
* **Adaptive:** ✅ (Optimized version) stops early if sorted.
* **When to use:**

  * Teaching sorting basics
  * Small datasets
  * Detecting already sorted arrays quickly

---

## **Topic: Insertion Sort Algorithm**

---

### **Concept**

Insertion Sort is a **simple**, **stable**, and **in-place** sorting algorithm.

**Idea:**
We divide the array into two parts —

* **Left side (sorted part)**
* **Right side (unsorted part)**

At each step, we **pick one element** from the unsorted part and **insert it into its correct position** in the sorted part — by **shifting larger elements to the right**.

---

### **Step-by-Step Explanation**

1. Assume the **first element is already sorted**.
2. Pick the next element (key).
3. Compare it with the elements in the sorted part (move left).
4. Keep shifting larger elements one position ahead.
5. Insert the key at the correct position.
6. Repeat until all elements are placed properly.

---

### **Example**

**Input:**
`arr = [13, 46, 24, 52, 20, 9]`

**Dry Run:**

| Pass | Selected (Key) | Sorted Part Before   | Action                        | Sorted Part After       |
| ---- | -------------- | -------------------- | ----------------------------- | ----------------------- |
| 1    | 46             | [13]                 | 46 > 13 → no change           | [13, 46]                |
| 2    | 24             | [13, 46]             | shift 46 → insert 24          | [13, 24, 46]            |
| 3    | 52             | [13, 24, 46]         | 52 > 46 → no change           | [13, 24, 46, 52]        |
| 4    | 20             | [13, 24, 46, 52]     | shift 52, 46, 24 → insert 20  | [13, 20, 24, 46, 52]    |
| 5    | 9              | [13, 20, 24, 46, 52] | shift all → insert 9 at start | [9, 13, 20, 24, 46, 52] |

**Output:** `[9, 13, 20, 24, 46, 52]`

---

### **Code (C++)**

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to perform Insertion Sort
void insertion_sort(int arr[], int n) {

    // Outer loop runs from 1 to n-1 (we assume first element is already sorted)
    for (int i = 1; i < n; i++) {

        // 'key' is the element to be inserted into the sorted part
        int key = arr[i];

        // 'j' points to the last index of the sorted part
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // shift right
            j--;                  // move left
        }

        // Place the key at its correct position
        arr[j + 1] = key;
    }

    // Print the sorted array
    cout << "After Insertion Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Insertion Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    insertion_sort(arr, n);
    return 0;
}
```

---

### **Output**

```
Before Insertion Sort:
13 46 24 52 20 9
After Insertion Sort:
9 13 20 24 46 52
```

---

### **Time Complexity Analysis**

| Case                 | Time Complexity | Explanation                   |
| -------------------- | --------------- | ----------------------------- |
| **Best Case**        | O(N)            | Already sorted → no shifting  |
| **Average Case**     | O(N²)           | Some shifting happens         |
| **Worst Case**       | O(N²)           | Reverse sorted → max shifting |
| **Space Complexity** | O(1)            | In-place sorting              |

---

### **Properties**

| Property     | Value | Explanation                            |
| ------------ | ----- | -------------------------------------- |
| **Stable**   | ✅ Yes | Equal elements maintain relative order |
| **Adaptive** | ✅ Yes | Faster when array nearly sorted        |
| **In-place** | ✅ Yes | No extra space used                    |
| **Online**   | ✅ Yes | Can sort as elements arrive one by one |

---

### **Notes**

* Insertion Sort is best suited for **small** or **partially sorted arrays**.
* It is often used in **hybrid algorithms** like **Timsort** (Python’s built-in sort).
* Easy to implement and useful for learning “shifting vs swapping” logic.

---

### **Comparison Recap (with Selection & Bubble Sort)**

| Algorithm      | Best Case | Avg/Worst | Stable | Adaptive | Extra Space |
| -------------- | --------- | --------- | ------ | -------- | ----------- |
| Selection Sort | O(N²)     | O(N²)     | ❌      | ❌        | O(1)        |
| Bubble Sort    | O(N)      | O(N²)     | ✅      | ✅        | O(1)        |
| Insertion Sort | O(N)      | O(N²)     | ✅      | ✅        | O(1)        |

---

## **Topic: Merge Sort Algorithm**

---

### **Concept**

**Merge Sort** is a **Divide and Conquer** algorithm.
It works by **recursively dividing** the array into two halves,
sorting each half, and then **merging the sorted halves** into one sorted array.

---

### **How it Works (Step-by-Step)**

1. **Divide:**

   * Split the array into two halves until you get single-element subarrays (size 1).
2. **Conquer:**

   * Recursively sort both halves.
3. **Combine (Merge):**

   * Merge the two sorted halves into one sorted array.

The merging process ensures that both halves remain sorted after combination.

---

### **Visualization**

Let’s take example:
`arr = [13, 46, 24, 52, 20, 9]`

**Recursive Breakdown:**

```
[13, 46, 24, 52, 20, 9]
        /           \
 [13, 46, 24]     [52, 20, 9]
   /     \           /      \
[13,46] [24]     [52,20]   [9]
 /  \             /  \
[13] [46]       [52] [20]
```

Now we **merge upwards** step by step:

```
[13] + [46] → [13,46]
[52] + [20] → [20,52]
[13,46] + [24] → [13,24,46]
[20,52] + [9] → [9,20,52]
Final merge: [13,24,46] + [9,20,52] → [9,13,20,24,46,52]
```

**Final Sorted Array:** `[9, 13, 20, 24, 46, 52]`

---


#### Merge Sort Implementation Steps 

1. **Function signatures likho:** `mergeSort(arr, low, high)` + helper `merge(arr, low, mid, high)`.
2. **Base case add karo:** `if (low >= high) return;`
3. **Mid nikaalo:** `mid = (low + high) / 2;`
4. **Recursion calls:** left part `mergeSort(arr, low, mid)`; right part `mergeSort(arr, mid+1, high)`.
5. **Merge helper implement karo:** two pointers + `temp` vector + copy back.
6. **Main me test case + print helper** likh ke chalao.
7. **Edge cases** try karo: empty, 1 element, duplicates, already sorted, reverse sorted.

---
### **Code (C++)**

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted halves
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;  // temporary array to store merged result
    int left = low;    // start index of left half
    int right = mid + 1; // start index of right half

    // Merge until one half is exhausted
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back merged elements into original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive Merge Sort function
void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;  // base case: single element

    int mid = (low + high) / 2;

    // Recursively sort left half
    mergeSort(arr, low, mid);

    // Recursively sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both sorted halves
    merge(arr, low, mid, high);
}

int main() {
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();

    cout << "Before Merge Sort:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    mergeSort(arr, 0, n - 1);

    cout << "After Merge Sort:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
```

---

### **Output**

```
Before Merge Sort:
13 46 24 52 20 9
After Merge Sort:
9 13 20 24 46 52
```

---

### **Dry Run (Simplified)**

Let’s dry run with smaller input:
`arr = [3,1,4,2]`

```
Divide:
[3,1] | [4,2]
→ [3] [1] → merge → [1,3]
→ [4] [2] → merge → [2,4]

Merge final halves:
[1,3] + [2,4] → [1,2,3,4]
```

---

### **Complexity Analysis**

| Case        | Time Complexity | Explanation                       |
| ----------- | --------------- | --------------------------------- |
| **Best**    | O(N log N)      | Always divides and merges         |
| **Average** | O(N log N)      | Each level merges all elements    |
| **Worst**   | O(N log N)      | Even in reverse sorted            |
| **Space**   | O(N)            | Uses temporary array for merging  |
| **Stable**  | ✅ Yes           | Maintains order of equal elements |

---

### **Why Merge Sort is Better**

| Sort           | Best Case      | Worst Case     | Space | Stable | Nature    |
| -------------- | -------------- | -------------- | ----- | ------ | --------- |
| Selection      | O(N²)          | O(N²)          | O(1)  | ❌      | Iterative |
| Bubble         | O(N)           | O(N²)          | O(1)  | ✅      | Iterative |
| Insertion      | O(N)           | O(N²)          | O(1)  | ✅      | Iterative |
| **Merge Sort** | **O(N log N)** | **O(N log N)** | O(N)  | ✅      | Recursive |

---

### **Notes**

* **Divide and Conquer** approach → efficient and predictable.
* **Used in:**

  * External sorting (files too large for memory)
  * Python’s `Timsort` (partly based on merge sort)
* **Downside:** Needs extra space O(N).
* **Advantage:** Time complexity guaranteed O(N log N) always.

---

### **Quick Summary**

| Property             | Merge Sort       |
| -------------------- | ---------------- |
| **Type**             | Divide & Conquer |
| **Time Complexity**  | O(N log N)       |
| **Space Complexity** | O(N)             |
| **Stable**           | Yes              |
| **Recursive**        | Yes              |
| **In-place**         | No               |



---

## **Topic: Quick Sort Algorithm**

---

### **Concept**

**Quick Sort** is a **Divide and Conquer** sorting algorithm.

**Main Idea:**

* Select one element as a **pivot**.
* Rearrange array so that:

  * All elements smaller than pivot come **before it**
  * All elements greater than pivot come **after it**
* Then recursively sort both left and right halves.

---

### **Steps**

1. **Pick a pivot** element (commonly the last element or random).
2. **Partition** the array around the pivot:

   * Place pivot at its correct sorted position.
   * Move all smaller elements to its left, larger to its right.
3. **Recursively sort** left and right subarrays.

---

### **Visualization (Example)**

Let’s take:
`arr = [13, 46, 24, 52, 20, 9]`
Let’s choose **pivot = last element = 9**

**Partition 1:**

* Compare each element with 9
* Every element > 9, so nothing swaps
* Finally, place 9 at correct position (index 0)

→ `[9, 46, 24, 52, 20, 13]`
Now pivot `9` is at correct place.

Left part = empty, Right part = `[46, 24, 52, 20, 13]`

**Partition 2:** pivot = `13`
→ `[9, 13, 24, 52, 20, 46]`

And so on…
Eventually → `[9, 13, 20, 24, 46, 52]`

---

### **Code (C++)**

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to partition the array around a pivot
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];  // choose last element as pivot
    int i = low - 1;        // i points to last smaller element's index

    // Loop to move smaller elements to left of pivot
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {       // if current element < pivot
            i++;                    // move pointer for smaller region
            swap(arr[i], arr[j]);   // bring smaller element forward
        }
    }

    // Place pivot at its correct position (after all smaller elements)
    swap(arr[i + 1], arr[high]);
    return i + 1;                   // return pivot index
}

// Recursive Quick Sort function
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        // Partition array, pivotIndex = position where pivot is now fixed
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);   // left side
        quickSort(arr, pivotIndex + 1, high);  // right side
    }
}

int main() {
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();

    cout << "Before Quick Sort:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    quickSort(arr, 0, n - 1);

    cout << "After Quick Sort:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
```

---

### **Output**

```
Before Quick Sort:
13 46 24 52 20 9
After Quick Sort:
9 13 20 24 46 52
```

---

### **Step-by-Step Dry Run**

`arr = [13, 46, 24, 52, 20, 9]`

**Initial:** low = 0, high = 5, pivot = 9
`i = -1`
No element < 9 → `i` stays `-1`
Swap `arr[i+1]` & `pivot` → swap(0,5)

`arr → [9,46,24,52,20,13]`
pivot index = 0

Now sort:

* Left = none
* Right = `[46,24,52,20,13]` (low=1, high=5, pivot=13)

**Partition 2:** pivot = 13
→ one element (9) already sorted
After partition → `[9,13,24,52,20,46]`

**Continue recursively**:

* Left: none
* Right: `[24,52,20,46]`
  Eventually becomes `[9,13,20,24,46,52]`

---

### **Important Notes**

| Concept          | Description                                   |
| ---------------- | --------------------------------------------- |
| **Pivot**        | Can be first, last, middle, or random element |
| **Partitioning** | Ensures pivot placed correctly                |
| **In-place**     | Yes — no extra array like Merge Sort          |
| **Stable**       | ❌ No — relative order may change              |
| **Recursive**    | Yes — divide array into halves repeatedly     |

---

### **Complexity Analysis**

| Case                 | Time Complexity | Explanation                                                 |
| -------------------- | --------------- | ----------------------------------------------------------- |
| **Best**             | O(N log N)      | Pivot divides array equally                                 |
| **Average**          | O(N log N)      | Random distribution                                         |
| **Worst**            | O(N²)           | Pivot always smallest/largest (sorted/reverse sorted array) |
| **Space Complexity** | O(log N)        | Due to recursion stack (not arrays)                         |

---

### **Quick Sort vs Merge Sort**

| Feature         | Quick Sort        | Merge Sort       |
| --------------- | ----------------- | ---------------- |
| **Approach**    | Divide & Conquer  | Divide & Conquer |
| **Extra Space** | O(log N)          | O(N)             |
| **In-place**    | ✅ Yes             | ❌ No             |
| **Stable**      | ❌ No              | ✅ Yes            |
| **Best for**    | In-memory sorting | External sorting |
| **Worst Case**  | O(N²)             | O(N log N)       |

---

### **Common Mistakes**

1. Forgetting `i = low - 1`
2. Using wrong range in recursion (`pivotIndex` boundaries)
3. Forgetting base condition `if (low < high)`
4. Not handling equal elements → use `<` not `<=` to avoid infinite loops

---

### **Improved (Randomized Quick Sort)**

To avoid worst case (like already sorted array),
we can **choose pivot randomly**:

```cpp
int randomPartition(vector<int>& arr, int low, int high) {
    int randomPivot = low + rand() % (high - low + 1);
    swap(arr[randomPivot], arr[high]);
    return partition(arr, low, high);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = randomPartition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
```

Now the **worst case (O(N²)) is extremely rare**.

---

### **Summary**

| Property             | Quick Sort                  |
| -------------------- | --------------------------- |
| **Type**             | Divide & Conquer            |
| **Time Complexity**  | O(N log N) avg, O(N²) worst |
| **Space Complexity** | O(log N)                    |
| **Stable**           | No                          |
| **In-place**         | Yes                         |
| **Best Case**        | Balanced partitions         |
| **Worst Case**       | Sorted/Reverse sorted input |

---
