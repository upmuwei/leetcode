//知道秘密的人数
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> people(forget, 0);
        people[0] = 1;
        for(int i = 1; i < n; i++) {
            long newPeople = 0;
            for(int j = forget - 1; j > 0; j--) {
                people[j] = people[j - 1];
            }
            for(int k = delay; k < forget; k++) {
                newPeople += people[k];
                newPeople %= (1000000000 + 7);
            }
            people[0] = newPeople;
        }
        long sum = 0;
        for(int i = 0; i < forget; i++) {
            sum += people[i];
            sum %= (1000000000 + 7);
        }
        return sum;
    }
};