#include <bits/stdc++.h>
using namespace std;

/* ------------------------------
   1. SELECTION SOR
//    https://www.geeksforgeeks.org/problems/selection-sort/1
   ------------------------------

   INTUITION
   ------------------------------
   - Think of the array as divided into two parts:
       1) Sorted part (begins empty)
       2) Unsorted part
   - In every step, you SELECT the smallest value from the
     unsorted part and put it in its correct position in the
     sorted part.
   - Sorted region grows from the left side.

   WHY THIS WORKS:
   - Smallest element MUST be placed at index 0.
   - Second smallest MUST be at index 1.
   - Continue this until array is sorted.

   ALGORITHM (Step-by-Step)
   -------------------------
   For i = 0 to n-2:
       1) minIndex = i
       2) Scan j = i+1 to n-1:
             if arr[j] < arr[minIndex]
                 minIndex = j
       3) Swap arr[i] with arr[minIndex]

   TIME COMPLEXITY:
   - Always O(N^2)

   SPACE COMPLEXITY:
   - O(1) in-place

   STABILITY:
   - Not stable (swap may break equal-order)
*/

// Function to perform selection sort on the given array.
void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // find index of minimum element in remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swap current element with minimum element found
        swap(arr[i], arr[minIndex]);
    }
}

/*
DRY RUN
Array = [13, 46, 24, 52, 20, 9]

i=0 → minIndex after full scan = 5
Swap arr[0], arr[5]
→ [9,46,24,52,20,13]

i=1 → minIndex = 5
→ [9,13,24,52,20,46]

i=2 → minIndex = 4
→ [9,13,20,52,24,46]

i=3 → minIndex = 4
→ [9,13,20,24,52,46]

i=4 → minIndex = 5
→ [9,13,20,24,46,52]
*/

/* ------------------------------
   2. BUBBLE SORT
// https://www.geeksforgeeks.org/problems/bubble-sort/1
   ------------------------------

   INTUITION
   ----------
   - Adjacent values are compared.
   - Larger values "bubble up" toward the right end.
   - After each full pass, the largest unsorted value is settled.

   WHY THIS WORKS:
   - Each pass guarantees the next largest element moves to its
     correct final position.

   ALGORITHM
   ----------
   For i = 0 to n-2:
       swapped = false
       For j = 0 to n-i-2:
           If arr[j] > arr[j+1]:
               swap and mark swapped = true
       If no swap → array already sorted → break early

   TIME COMPLEXITY:
   - Worst and average O(N^2)
   - Best O(N) when array already sorted

   SPACE COMPLEXITY:
   - O(1)

   STABILITY:
   - Stable
*/

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    // n = total number of elements in the array

    // Outer loop controls number of passes
    // After each pass, the largest element moves to the end
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        // swapped tracks whether any swap happened in this pass

        // Inner loop compares adjacent elements
        // Last i elements are already sorted, so we don't touch them
        for (int j = 0; j < n - i - 1; j++)
        {
            // If current element is greater than next element
            // swap them to move larger element towards the end
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                // swap adjacent elements

                swapped = true;
                // mark that a swap has occurred
            }
        }

        // If no swaps happened in the entire pass,
        // the array is already sorted, so we stop early
        if (!swapped)
            break;
    }
}

/*
DRY RUN
[13, 46, 24, 52, 20, 9]

Pass 1 → bubble largest (52) to end
Pass 2 → bubble second-largest
Pass 3 → continue until sorted
Final → [9,13,20,24,46,52]
*/

/* ------------------------------
   3. INSERTION SORT
// https://www.geeksforgeeks.org/problems/insertion-sort/1
   ------------------------------

   INTUITION
   ----------
   - Left part of the array is considered sorted.
   - Current element (key) is inserted at the correct position in
     the left sorted region.

   REAL ANALOGY:
   - Like sorting playing cards in your hand one-by-one.

   ALGORITHM
   ----------
   For i = 1 to n-1:
       key = arr[i]
       j = i - 1
       while j >= 0 and arr[j] > key:
           arr[j+1] = arr[j]
           j--
       arr[j+1] = key

   TIME COMPLEXITY:
   - Best: O(N)
   - Worst: O(N^2)

   SPACE COMPLEXITY:
   - O(1)

   STABILITY:
   - Stable
*/

// Function to perform insertion sort on the given array
void insertionSort(vector<int> &arr)
{

    int n = arr.size(); // size of the array

    // Start from second element because first element is already "sorted"
    for (int i = 1; i < n; i++)
    {

        int key = arr[i]; // element to be placed at correct position
        int j = i - 1;    // index of previous element

        /*
            Move elements of arr[0..i-1] that are greater than key
            one position ahead to make space for key
        */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // shift element to the right
            j--;
        }

        // Place key at its correct sorted position
        arr[j + 1] = key;
    }
}

/*
DRY RUN
[13,46,24,52,20,9]

Insert 46 → correct
Insert 24 → shift 46
Insert 52 → correct
Insert 20 → shift 52,46,24
Insert 9 → shift everything
Final → [9,13,20,24,46,52]
*/

/* ------------------------------
   4. MERGE SORT
//    https://www.geeksforgeeks.org/problems/merge-sort/1
   ------------------------------

   INTUITION
   ----------
   - Divide array into two halves recursively.
   - Sort each half.
   - Merge the two sorted halves using two-pointer technique.

   THE KEY INSIGHT:
   - Small sorted pieces can be merged efficiently.
   - Entire sorting comes from merging.

   ALGORITHM
   ----------
   mergeSort(arr, low, high):
       if low >= high: return
       mid = (low + high) / 2
       mergeSort(arr, low, mid)
       mergeSort(arr, mid+1, high)
       merge(arr, low, mid, high)

   merge(arr, low, mid, high):
       create temp[]
       left = low
       right = mid+1
       while left ≤ mid and right ≤ high:
           push smaller of arr[left], arr[right]
       push remaining left elements
       push remaining right elements
       copy temp back to arr

   TIME COMPLEXITY:
   - Always O(N log N)

   SPACE COMPLEXITY:
   - O(N) extra array

   STABILITY:
   - Stable
*/
// Function to merge two sorted subarrays
// arr[l..mid] and arr[mid+1..r]
void merge(vector<int> &arr, int l, int mid, int r)
{

    vector<int> temp;    // temporary array to store merged result
    int left = l;        // pointer for left subarray
    int right = mid + 1; // pointer for right subarray

    // Merge elements from both halves in sorted order
    while (left <= mid && right <= r)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from left half (if any)
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right half (if any)
    while (right <= r)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy merged elements back to original array
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
}

// Main merge sort function (matches given signature)
void mergeSort(vector<int> &arr, int l, int r)
{
    // Base case: single element or invalid range
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;

    // Sort left half
    mergeSort(arr, l, mid);

    // Sort right half
    mergeSort(arr, mid + 1, r);

    // Merge the two sorted halves
    merge(arr, l, mid, r);
}

/*
DRY RUN
Split → [13,46,24] and [52,20,9]
Sort left → [13,24,46]
Sort right → [9,20,52]
Merge → [9,13,20,24,46,52]
*/

/* ------------------------------
   5. QUICK SORT
// https://www.geeksforgeeks.org/problems/quick-sort/1
   ------------------------------

   INTUITION
   ----------
   - Choose a pivot.
   - Partition array: elements smaller than pivot go left,
     greater go right.
   - Recursively sort left and right parts.

   WHY IT WORKS:
   - Partition ensures pivot is at its correct final position.

   ALGORITHM
   ----------
   partition(arr, low, high):
       pivot = arr[high]
       i = low-1
       for j = low to high-1:
           if arr[j] < pivot:
               i++
               swap arr[i], arr[j]
       swap arr[i+1], arr[high]
       return i+1

   quickSort(arr, low, high):
       if low < high:
           p = partition(arr, low, high)
           quickSort(arr, low, p-1)
           quickSort(arr, p+1, high)

   TIME COMPLEXITY:
   - Best/Average: O(N log N)
   - Worst: O(N^2) when pivot is poor

   SPACE COMPLEXITY:
   - O(log N) recursion stack

   STABILITY:
   - Not stable
*/

// Function to partition the array using last element as pivot
int partition(vector<int> &arr, int low, int high)
{

    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;       // index of smaller element

    // Traverse elements from low to high-1
    for (int j = low; j < high; j++)
    {

        // If current element is smaller than pivot
        if (arr[j] < pivot)
        {
            i++;                  // move smaller element index forward
            swap(arr[i], arr[j]); // place element at correct position
        }
    }

    // Place pivot at its correct sorted position
    swap(arr[i + 1], arr[high]);

    // Return pivot index
    return i + 1;
}

// Function to perform Quick Sort on the array
void quickSort(vector<int> &arr, int low, int high)
{

    // Base condition: sort only if there are at least 2 elements
    if (low < high)
    {

        // Partition the array and get pivot index
        int p = partition(arr, low, high);

        // Recursively sort elements before pivot
        quickSort(arr, low, p - 1);

        // Recursively sort elements after pivot
        quickSort(arr, p + 1, high);
    }
}

/*
DRY RUN
Pivot = last element

Initial: [13,46,24,52,20,9]
Place pivot 9 at position 0 → [9,46,24,52,20,13]
Sort right side similarly
Final sorted array → [9,13,20,24,46,52]
*/

/* ------------------------------
   MAIN DRIVER FUNCTION
   ------------------------------
*/
int main()
{
    vector<int> original = {13, 46, 24, 52, 20, 9};

    // Helper lambda to print array
    auto printArray = [](const vector<int> &arr)
    {
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    };

    // 1. Selection Sort
    vector<int> arr1 = original;
    selectionSort(arr1);
    cout << "Selection Sort: ";
    printArray(arr1);

    // 2. Bubble Sort
    vector<int> arr2 = original;
    bubbleSort(arr2);
    cout << "Bubble Sort:    ";
    printArray(arr2);

    // 3. Insertion Sort
    vector<int> arr3 = original;
    insertionSort(arr3);
    cout << "Insertion Sort: ";
    printArray(arr3);

    // 4. Merge Sort
    vector<int> arr4 = original;
    mergeSort(arr4, 0, arr4.size() - 1);
    cout << "Merge Sort:     ";
    printArray(arr4);

    // 5. Quick Sort
    vector<int> arr5 = original;
    quickSort(arr5, 0, arr5.size() - 1);
    cout << "Quick Sort:     ";
    printArray(arr5);

    return 0;
}
