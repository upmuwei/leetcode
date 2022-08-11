class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // bool sign[n + 1] = false;
        // vector<bool> sign(n+1,false);
         vector<vector<int>> result;
        // vector<int> p(n);
        vector<int> tmp;
        combineCir(n, k, 1, result, tmp);
        return result;
    }

    void combineCir(int n, int k, int begin, vector<vector<int>>& result, vector<int>& tmp) {
        
        for(int i = begin; i <= n; i++) {
            tmp.push_back(i);
            if(k == 1) {
                result.push_back(tmp);
            } else{
                combineCir(n, k - 1, i + 1, result, tmp);
            }
            tmp.pop_back();
        }
    } 
};