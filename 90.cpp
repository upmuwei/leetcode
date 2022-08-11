class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> tmp;
        result.push_back(tmp);
        for(int i = 1; i < nums.size(); i++) {
            combine(nums, i, 0, result, tmp);
        }
        result.push_back(nums);
        return result;
    }

    void combine(vector<int>& nums, int k, int begin, vector<vector<int>>& result, vector<int>& tmp) {
        int length = nums.size();
        for(int i = begin; i < length; i++) {
            tmp.push_back(nums[i]);
            if(k == 1) {
                result.push_back(tmp);
            } else{
                combine(nums, k - 1, i + 1, result, tmp);
            }
            tmp.pop_back();
            while(i+1<length&&nums[i+1]==nums[i]) {
                i++;
            }
        }
        
    } 
};