## Second Largest

Problem Link https://www.geeksforgeeks.org/problems/second-largest3735/1


### Brute forces 
* TC O(2n) ~ O(n)

```cpp
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
    int n = arr.size();
    
    
    int largest = arr[0];
    for(int i = 0;  i<n; i++){
        if(arr[i] > largest)
            largest = arr[i];
    }
    int secLargest = -1;
    for(int i = 0; i<n; i++){
        if(arr[i] < largest && arr[i] > secLargest){
            secLargest = arr[i];
        }
    }
    
    return secLargest;
    }
};
```

### Better
* Time Complexity: O(n) (ek hi traversal)
* Space Complexity: O(1)


```cpp
class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        
        int largest = arr[0];
        int secLargest = -1;  // assume -1 if no second largest
        
        for(int i = 1; i < n; i++) {
            if(arr[i] > largest) {
                secLargest = largest;   // update 2nd largest
                largest = arr[i];       // update largest
            } 
            else if(arr[i] < largest && arr[i] > secLargest) {
                secLargest = arr[i];    // update if between
            }
        }
        
        return secLargest;
    }
};
```