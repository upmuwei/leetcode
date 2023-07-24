class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> jewelSet;
        for(char c : jewels) {
            jewelSet.insert(c);
        }
        int count = 0;
        for(char stone : stones) {
            if(jewelSet.find(stone) != jewelSet.end()) {
                count++;
            }
        }
        return count;
    }
};