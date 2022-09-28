class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while(low < high) {
            int middle = (low +high) / 2;
            if(middle-1>=0 &&arr[middle] > arr[middle - 1] && arr[middle] > arr[middle +1]) {
                return middle;
            } else if(middle + 1 < arr.size() && arr[middle] < arr[middle +1]) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return high;
    }
};