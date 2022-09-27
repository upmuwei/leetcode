class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> lens;
        int max = 1;
        for(int i = 0; i < arr.size(); i++) {
            if(lens[arr[i] - difference] != 0) {
                lens[arr[i]] = 1 + lens[arr[i] - difference];
            } else {
                lens[arr[i]] = 1;
            }
            if(lens[arr[i]] > max) {
                max = lens[arr[i]];
            } 
        }
        return max;
    }
};