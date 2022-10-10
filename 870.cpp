class Solution {
public:
    //对索引建立排序
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(nums1.begin(), nums1.end());
        sort(idx.begin(), idx.end(),[&](int a, int b) {return nums2[a] < nums2[b];});
        int L = 0, R = n - 1;
        for (int i : nums1) { // 遍历nums1
            if (i > nums2[idx[L]]) nums2[idx[L++]] = i; // 可以满足 nums1[i] > nums2[i]
            else nums2[idx[R--]] = i; //丢到数组最后
        }
        return nums2;
    }
};