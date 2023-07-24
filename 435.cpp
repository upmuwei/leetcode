class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int> b) {
            return a[1] < b[1];
        });
        int index = 0;
        int count = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < intervals[index][1]) {
                count++;
            } else {
                index = i;
            }
        }
        return count;
    }
};