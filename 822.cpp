class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> repeats;
        int min = INT_MAX;
        for(int i = 0; i < fronts.size(); i++) {
            if(fronts[i] == backs[i]) {
                repeats.insert(fronts[i]);
            }
        }
        for(int i = 0; i < fronts.size(); i++) {
            if(fronts[i] != backs[i]) {
                if(repeats.find(fronts[i]) == repeats.end()) {
                    if(min > fronts[i]) {
                        min = fronts[i];
                    }
                }
                if(repeats.find(backs[i]) == repeats.end()) {
                    if(min > backs[i]) {
                        min = backs[i];
                    }
                }
            }
        }
        if(min == INT_MAX) {
            return 0;
        }
        return min;
    }
};