```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target);

        // If target not found at all
        if (first == -1) {
            return {-1, -1};
        }

        int last = lastOccurrence(nums, target);

        // We must return range, not count
        return {first, last};
    }

    int firstOccurrence(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                first = mid;
                high = mid - 1;   // go left
            } 
            else if (arr[mid] < x) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return first;
    }

    int lastOccurrence(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                last = mid;
                low = mid + 1;   // go right
            } 
            else if (arr[mid] < x) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return last;
    }
};
```