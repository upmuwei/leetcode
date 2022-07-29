class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                tmp.push_back(nums1[i]);
                i++;
            } else {
                tmp.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m) {
            tmp.push_back(nums1[i++]);
        }
        for(i = 0; i <  tmp.size(); i++) {
            nums1[i] = tmp[i];
        }       
        for(; j < n; j++) {
            nums1[i++] = nums2[j];
        } 
    }
};