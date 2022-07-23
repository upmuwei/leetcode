class Solution {
public:
    vector<vector<int>> result;
    int sign[7];
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        arrange(nums, tmp);
        return result;
    }

    void arrange(vector<int>& nums, vector<int> tmp) {
        if(tmp.size() == nums.size()) {
            result.push_back(tmp);
        }
        for(int i =0; i < nums.size(); i++) {
            if(!sign[i]) {
                sign[i] = true;
                tmp.push_back(nums[i]);
                arrange(nums, tmp);
                tmp.pop_back();
                sign[i] = false;
            }
        }
    }
};