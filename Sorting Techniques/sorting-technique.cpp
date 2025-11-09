#include <bits/stdc++.h>
using namespace std;

// 1. SELECTION SORT


// Intuition :
// Repeatedly select the smallest element from the unsorted part 
// and place it at the beginning (sorted region grows from left).

// Algorithm :
// - For each index i (0 to n-2):
//     - Assume i is the smallest (minIndex = i)
//     - Scan remaining array (j = i+1 to n-1)
//     - If arr[j] < arr[minIndex], update minIndex
//     - Swap arr[i] and arr[minIndex]
// - Repeat until array sorted

// TC : O(N^2) for all cases (best, avg, worst)
// SC : O(1)
// Not stable,  In-place
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the minimum element in remaining unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap smallest element with element at index i
        swap(arr[i], arr[minIndex]);
    }
}


// 2. BUBBLE SORT


// Intuition :
// Repeatedly compare adjacent elements and “bubble” the largest
// element to the end in each pass.

// Algorithm :
// - For i = 0 to n-2:
//     - For j = 0 to n-i-2:
//         - If arr[j] > arr[j+1], swap them
// - After each pass, last i elements are sorted.

//  TC : O(N^2), Best: O(N) if optimized with flag
//  SC : O()//  Stable,  In-place
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps → array already sorted
        if (!swapped) break;
    }
}


// 3. INSERTION SORT


// Intuition :
// Take one element at a time from the unsorted part
// and insert it in its correct position within the sorted part.

// Algorithm :
// - For i = 1 to n-1:
//     - Store current element as key = arr[i]
//     - Move elements greater than key one step right
//     - Insert key at correct position

//  TC : Best O(N) | Avg/Worst O(N^2)
//  SC : O()//  Stable,  In-place
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift larger elements to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at correct position
        arr[j + 1] = key;
    }
}


// 4. MERGE SORT (Divide and Conquer)


// Intuition :
// Recursively divide array into two halves, sort them, 
// then merge the two sorted halves.

// Algorithm :
// - Divide array into two halves
// - Recursively sort both halves
// - Merge both sorted halves using two pointers

// TC : O(N log N) always
// SC : O(N) due  temp array
// Stable,  Not In-place

// Merge two sorted halves: [low..mid] and [mid+1..high]
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merge elements into temp
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    // Copy temp array back to original
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive Merge Sort function
void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return; // Base case

    int mid = (low + high) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge the two halves
    merge(arr, low, mid, high);
}


// 5. QUICK SORT (Divide and Conquer, In-place)


// Intuition :
// Select a pivot and partition array such that
// elements smaller than pivot are on left, greater on right.
// Recursively repeat the same for left and right parts.

// Algorithm :
// - Choose pivot (commonly last element)
// - Partition array around pivot
// - Recursively quickSort left and right halves

// TC : Best/Average O(N log N), Worst O(N^2)
// SC : O(log N) recursion stack
// Not Stable,  In-place

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose pivot
    int i = low - 1;        // i marks end of smaller elements

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // place smaller element to left region
        }
    }

    swap(arr[i + 1], arr[high]);  // Place pivot in correct position
    return i + 1;                 // Return pivot index
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition array around pivot
        int pivotIndex = partition(arr, low, high);

        // Recursively sort left and right parts
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


// MAIN DRIVER FUNCTION

int main() {
    int arr1[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Before Sorting: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n\n";

    selection_sort(arr1, n);
    cout << "After Selection Sort: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n\n";

    int arr2[] = {13, 46, 24, 52, 20, 9};
    bubble_sort(arr2, n);
    cout << "After Bubble Sort: ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";

    int arr3[] = {13, 46, 24, 52, 20, 9};
    insertion_sort(arr3, n);
    cout << "After Insertion Sort: ";
    for (int x : arr3) cout << x << " ";
    cout << "\n\n";

    vector<int> arr4 = {13, 46, 24, 52, 20, 9};
    mergeSort(arr4, 0, n - 1);
    cout << "After Merge Sort: ";
    for (int x : arr4) cout << x << " ";
    cout << "\n\n";

    vector<int> arr5 = {13, 46, 24, 52, 20, 9};
    quickSort(arr5, 0, n - 1);
    cout << "After Quick Sort: ";
    for (int x : arr5) cout << x << " ";
    cout << "\n";

    return 0;
}

