class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p;
        p.push_back(p1);
        p.push_back(p2);
        p.push_back(p3);
        p.push_back(p4);
        sort(p.begin(), p.end());
        if(p[0][0] == p[1][0] && p[0][1] == p[1][1]) {
            return false;
        }
        int t1 = (p[1][1] - p[0][1]) * ((p[1][1] - p[0][1])) + (p[1][0] - p[0][0]) * ((p[1][0] - p[0][0]));
        int t2 = (p[2][0] - p[0][0]) * (p[2][0] - p[0][0]) + (p[2][1] - p[0][1]) * (p[2][1] - p[0][1]);
        int t3 = (p[2][0] - p[1][0]) * (p[2][0] - p[1][0]) + (p[2][1] - p[1][1]) * (p[2][1] - p[1][1]);
        int t4 = (p[3][0] - p[1][0]) * (p[3][0] - p[1][0]) + (p[3][1] - p[1][1]) * (p[3][1] - p[1][1]);
        if(t1 != t2) {
            return false;
        }
        if(t1 != t4) {
            return false;
        }
        if((t1 + t2) != t3) {
            return false;
        }
        return true;
    }
};