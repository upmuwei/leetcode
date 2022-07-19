class Solution {
public:
    //回溯法，深度优先遍历
    //如不能遍历，想到树的思想的使用
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string s;
        countTree(n, n, s);
        return result;
    }

    void countTree(int depth1, int depth2, string s) {
        if((!depth1) && (!depth2)) {
            result.push_back(s);
            return;
        }
        if(depth1 > depth2) {
            return;
        } 
        if(depth1 < 0) {
            return;
        }
        s.push_back('(');
        countTree(depth1 -1, depth2,s);
        s.pop_back();
        s.push_back(')');
        countTree(depth1, depth2 -1, s);
        return;
    }
};