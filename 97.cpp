class Solution {
public:
    set<vector<int>> repeat;
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s3.size() != (s1.size() + s2.size())) {
            return false;
        }
        return seek(s3, s1, s2, 0, 0, 0);
    }

    bool seek(string& s1, string& s2, string& s3, int i, int j, int k) {
        if(i == s1.size()) {
            return true;
        }
        if(j < s2.size() && s1[i] == s2[j]) {
            vector<int> t(3);
            t[0] = i + 1;
            t[1] = j + 1;
            t[2] = k;
            if(repeat.count(t) == 0) {
                repeat.insert(t);
            if(seek(s1, s2, s3, i + 1,  j + 1, k)) {
                return true;
            }  
            }
            
        }
        if(k < s3.size() && s1[i] == s3[k]) {
            vector<int> t(3);
            t[0] = i + 1;
            t[1] = j;
            t[2] = k + 1;
            if(repeat.count(t) == 0) {
                repeat.insert(t);
                return seek(s1, s2, s3, i + 1, j, k + 1);
            }
            
        }
        return false;
    }
};