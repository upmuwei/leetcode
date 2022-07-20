#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> results;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        match(result, candidates, 0, target);
      
        return results;
    }

    void match(vector<int>& result, vector<int>& candidates, int i, int target) {
        
        if(!target) {
            for(auto t : result) {
                cout << t << " ";
            }
            cout << endl;
            results.push_back(result);
            return;
        }
        int t = 0;
        for(; i< candidates.size(); i++) {
            if(candidates[i] == t) {
                continue;
            } else {
                t = candidates[i];
            }
            if(candidates[i] > target) {
                return;
            }
            target -= candidates[i];
            result.push_back(candidates[i]);
            match(result, candidates, i + 1, target);
            result.pop_back();
            target += candidates[i];        
        }
        
        return;
    }
}; 

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    
    Solution solution;
    solution.combinationSum2(candidates,target);
    return 0;
}