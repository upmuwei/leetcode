class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> result;
        vector<int> value;
        vector<int> assit;
        map<int, int> count;
        for(int i =0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        for(auto t : count) {
            value.push_back(t.first);
            assit.push_back(t.second);
        }
        for(int i = 0; i < value.size(); i++) {
            int p = i;
            for(int j = i + 1; j < value.size(); j++) {
                if(assit[j] < assit[p]) {
                    p = j;
                } else if(assit[j] == assit[p]) {
                    if(value[p] < value[j]) {
                        p = j;
                    }
                }
            }
            if(p != i) {
                swap(value[p], value[i]);
                swap(assit[p], assit[i]);
            }
        }
        for(int i = 0; i < value.size(); i++) {
            for(int j = 0; j < assit[i]; j++) {
                result.push_back(value[i]);
            }
        }
        return result;
    }
};