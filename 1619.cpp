class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int begin = arr.size() * 0.05;
        int end = arr.size() - begin;
        double sum = 0;
        for(int i = begin; i < end; i++) {
            sum += arr[i];
        }
        return sum / (end - begin);
    }
};