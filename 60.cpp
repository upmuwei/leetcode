class Solution {
public:
    int t = 0;
    int num = 0;
    vector<int> s;
    string getPermutation(int n, int k) {
        bool sign[10] = {false};
        traverse(n, k, sign);
        string result;
        for(auto c : s) {
            result.push_back(c + '0');
        }
        return result;
    }

    void traverse(int n, int k, bool *sign) {
        for(int i = 1; i <=n; i++) {
            if(!sign[i]) {
                t++;
                s.push_back(i);
                sign[i] = true;
                if(t == n) {
                    num++;
                    if(num == k) {
                        return;
                    }
                    sign[i] = false;
                    t--;
                    s.pop_back();
                    continue;
                }
                traverse(n,k,sign);
                if(num == k) {
                    return;
                }
                sign[i] = false;
                s.pop_back();
                t--;
            }
            if(num == k) {
                return;
            }
        }
    }
};