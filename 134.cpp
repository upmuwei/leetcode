class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int debt = 0, own = 0, index = -1;
        for(int i = 0; i < gas.size(); i++) {
            int surplus = gas[i] + own - cost[i];
            if(surplus >= 0) {
                if(index == -1) {
                    index = i;
                }
                own = surplus;
            }
            else {
                debt += surplus;
                own = 0;
                index = -1;
            }
        }
        if(own + debt >= 0) {
            return index;
        }
        return -1;
    }
};