#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem :
// Example :
// Constraint :

// 🔴 Approach 1 : Selection Sort
// Intuition :
// Algo :
// TC :
// SC :
void selection_sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        swap(arr[minIndex], arr[i]);
    }
    // Print the sorted array
    cout << "After selection Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}
// 🔵 Approach 2 : Bubble Sort
// Intuition :
// Algo :
// TC :
// SC :
void bubble_sort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }   
        if(didSwap == 0) break;
    }
    cout << "After Bubble Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}


// 🟢 Approach 3 : Insertion Sort
// Intuition :
// Algo :
// TC :
// SC :

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Print the sorted array
    cout << "After Insertion Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

// ⚪ Approach 4 :
// Intuition :
// Algo :
// TC :
// SC :

// 🟡 Approach 5 : Quick Sort
// Intuition :
// Algo :
// TC :
// SC :

int main()
{
   
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);
    bubble_sort(arr, n);
    insertion_sort(arr, n);
    return 0;
}