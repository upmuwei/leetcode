class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<int> sizeIndex;
        vector<vector<int>> result;
        for(int i = 0; i < groupSizes.size(); i++) {
            int j = 0;
            for(; j < sizeIndex.size(); j++) {
                if(sizeIndex[j] == groupSizes[i]&&result[j].size() < groupSizes[i]) {
                    result[j].push_back(i);
                    break;
                }
            }
            if(j == sizeIndex.size()) {
                // cout << "1";
                vector<int> tmp;
                tmp.push_back(i);
                sizeIndex.push_back(groupSizes[i]);
                result.push_back(tmp);
            }
        }
        return result;
    }
};