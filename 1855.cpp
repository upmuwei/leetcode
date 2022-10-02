class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max = 0;
        for(int i = 0; i < nums1.size(); i++) {
            int low = i, high = nums2.size() - 1;
            while(low <= high) {
                int middle = (low + high) / 2;
                if(nums2[middle] >= nums1[i]) {
                    low = middle + 1;
                } else {
                    high = middle - 1;
                }
            }
            if(high - i > max) {
                max = high - i;
            }
        } 

        return max;
    } 
};