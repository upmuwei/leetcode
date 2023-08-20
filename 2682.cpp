class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        set<int> havingBall;
        int index = 0;
        havingBall.insert(index);
        for(int i = 0; i < n; i++) {
            index = (index + (i + 1) * k) % n;
            if(havingBall.find(index) != havingBall.end()) {
                break;
            } else {
                havingBall.insert(index);
            }
        }
        vector<int> result;
        for(int j = 0; j < n; j++) {
            if(havingBall.find(j) == havingBall.end()) {
                result.push_back(j + 1);
            }
        }
        return result;
    }
};