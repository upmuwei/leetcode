class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int min = intervals[0][0], max = intervals[0][1];
        int index = 0;
        for(int i = 1; i< intervals.size();) {
            if(intervals[i][0] <= max) {
                // cout << intervals[i][1] << endl;
                max = (intervals[i][1] > max ? intervals[i][1] : max);
            } else {
                vector<int> tmp;
                tmp.push_back(min);
                tmp.push_back(max);
                result.push_back(tmp);
                index = i;
                min = intervals[i][0];
                max = intervals[i][1];
            }
            i++;
        }
        vector<int> tmp;
        tmp.push_back(min);
        tmp.push_back(max);
        result.push_back(tmp);    
        return result;
    }
};