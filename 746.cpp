class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int p[cost.size() + 1];
        p[0] = p[1] = 0;
        for(int i = 2; i<= cost.size(); i++) {
            int t1 = p[i-1] + cost[i-1];
            int t2 = p[i-2] + cost[i-2];
            p[i] = t1 > t2 ? t2 : t1;
        }
        return p[cost.size()];
    }
};