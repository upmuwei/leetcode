class Solution {
    map<tuple<int, int>, bool> records;
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        if(sum % 2 != 0) {
            return false;
        }
        return find(nums, 0, sum / 2);
    } 

    bool find(vector<int>& nums, int index, int sum) {
        if(sum == 0) {
            return true;
        }
        if(index == nums.size() || sum < 0) {
            return false;
        }
        tuple<int, int> t(index, sum);
        if(records.find(t) != records.end()) {
            return records[t];
        }
        bool result = find(nums, index + 1, sum - nums[index]) || find(nums, index + 1, sum);
        records[tuple<int, int>(index, sum)] = result;
        return result;
    }
};