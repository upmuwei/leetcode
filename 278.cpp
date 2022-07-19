// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, middle;
        while(low <= high) {
            long tmp = (long)low + high;
            middle = tmp / 2;
            if(isBadVersion(middle)) {
                 high = middle -1;
            } else {
                low = middle + 1;
            }
        }
        return low;
    }
};