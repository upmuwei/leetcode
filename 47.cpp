class Solution {
public:
    vector<vector<int>> result;
    bool sign[9];
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        arrange(nums, tmp);
        return result;
    }

     void arrange(vector<int>& nums, vector<int> tmp) {
        if(tmp.size() == nums.size()) {
            result.push_back(tmp);
            return;
        }
        for(int i =0; i < nums.size(); i++) {
            if(!sign[i]) {
                sign[i] = true;
                tmp.push_back(nums[i]);
                arrange(nums, tmp);
                tmp.pop_back();
                sign[i] = false;
                while(((i +1) < nums.size())&&nums[i +1] == nums[i]) {
                    i++;
                }
            }
        }
        return;
    }
};