class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, avg = 0;
        for(auto t : nums) {
            sum += t;
        }
        if(sum%k != 0) {
            return false;
        }
        avg = sum / k;
        vector<int> used(k, 0);
        sort(nums.begin(), nums.end(), [](int a, int b) { return a > b;});
        return isCollection(nums, used, avg, 0);
    }

    bool isCollection(vector<int>& nums, vector<int>& used, int avg, int index) {
        if(index == nums.size()) {
            return true;
        }
        for(int i = 0; i < used.size(); i++) {
            if(i > 0 && used[i] == used[i - 1]) {
                continue;
            }
            used[i] += nums[index];
            if(used[i] <= avg && isCollection(nums, used, avg, index +1)) {
                return true;
            }
            used[i] -= nums[index];
        }
        return false;
    }
};