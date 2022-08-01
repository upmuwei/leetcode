class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int min = newInterval[0], max = newInterval[1];
        int j = 0;
        for(; j < intervals.size(); j++) {
           if(intervals[j][1] < min) {
               result.push_back(intervals[j]);
           } else if(intervals[j][0] > max) {
               break;
           }
           else {
               min = intervals[j][0] < min ? intervals[j][0] : min;
               max = intervals[j][1] > max ? intervals[j][1] : max;
           }
        }
        vector<int> tmp;
        tmp.push_back(min);
        tmp.push_back(max);
        result.push_back(tmp);
        for(; j< intervals.size(); j++) {
            result.push_back(intervals[j]);
        }
        return result;
    }
};