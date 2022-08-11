class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
        for(int i = begin; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            if(k == 1) {
                result.push_back(tmp);
            } else{
                combine(nums, k - 1, i + 1, result, tmp);
            }
            tmp.pop_back();
        }
    } 
};