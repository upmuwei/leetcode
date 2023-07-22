class Solution {
    map<int, int> elems;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            if(elems.find(nums[i]) != elems.end()) {
                if(i - elems[nums[i]] <= k) {
                    return true;
                }
                elems[nums[i]] = i;
            } else {
                elems[nums[i]] = i;
            }
        }
        return false;
    }
};