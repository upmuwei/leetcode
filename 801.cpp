class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> f(nums1.size(), vector<int>(2, 0));
        f[0][1] = 1;
        for(int i = 1; i < nums1.size(); i++) {
            f[i][0] = f[i][1] = i + 1;
        }
        for(int i = 1; i < nums1.size(); i++) {
            if(nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                f[i][0] = f[i-1][0];
                f[i][1] = f[i-1][1] + 1;
            }
            if(nums1[i] > nums2[i -1] && nums2[i] > nums1[i -1]) {
                f[i][0] = min(f[i][0], f[i-1][1]);
                f[i][1] = min(f[i][1], f[i-1][0] + 1);
            }
        }
        return min(f[nums1.size() - 1][0], f[nums1.size() - 1][1]);
    }
};