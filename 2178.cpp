class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2) {
            return {};
        }
        vector<long long> result;
        long long figure = 2;
        while(finalSum != 0) {
            finalSum -= figure;
            if(finalSum <= figure) {
                result.push_back(finalSum + figure);
                break;
            }
            result.push_back(figure);
            figure += 2;
        }
        return result;
    }
};