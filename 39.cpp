#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> results;
    bool repeat = false;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        match(result, candidates, 0, target, false);
      
        return results;
    }

    void match(vector<int>& result, vector<int>& candidates, int i, int target, bool sign) {
        
        if(!target) {
            for(auto t : result) {
                cout << t << " ";
            }
            cout << endl;
            if(!repeat) {
                results.push_back(result);
                repeat = true;
            } else {
                repeat = false;
            }
            return;
        }
        for(; i< candidates.size(); i++) {
            if(candidates[i] > target) {
                return;
            }
            if((i + 1) < candidates.size() && candidates[i + 1] == candidates[i]) {
                i++;
                continue;
            }
            target -= candidates[i];
            result.push_back(candidates[i]);
            match(result, candidates, i, target, true); 
            match(result, candidates, i + 1, target,false);
            if(sign) {
                result.pop_back();
                target += candidates[i];   
                break;
            }
            result.pop_back();
            target += candidates[i];        
            
        }
        
        return;
    }
}; 

int main() {
    vector<int> candidates = {3, 5, 8};
    int target = 11;
    
    Solution solution;
    solution.combinationSum2(candidates,target);
    return 0;
}