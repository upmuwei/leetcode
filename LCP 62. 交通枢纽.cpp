class Solution {
public:
    int transportationHub(vector<vector<int>>& path) {
        set<int> chu;
        set<int> zong;
        map<int, int> ru;
        for(int i = 0; i < path.size(); i++) {
            chu.insert(path[i][0]);
            zong.insert(path[i][0]);
            zong.insert(path[i][1]);
        }
        for(int i = 0; i < path.size(); i++) {
            if(chu.count(path[i][1]) == 0) {
                if(ru[path[i][1]] == 0) {
                    ru[path[i][1]] = 1;
                } else {
                    ru[path[i][1]]++;    
                }
                if(ru[path[i][1]] == zong.size() - 1) {
                    return path[i][1];
                }
            }
        }
        return - 1;
    }
};