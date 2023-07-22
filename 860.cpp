class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int own = 0, money[3] = {0};
        for(int bill : bills) {
            if(bill - 5 > own) {
                return false;
            } else {
                if(bill == 10 && !money[0]) {
                    return false;
                } else if(bill == 20 && money[0] == 0) {
                    return false;
                } else if(bill == 20 && (money[1] == 0 && money[0] < 3)) {
                    return false;
                }
                money[bill / 10]++;
                if(bill == 20 && money[1] > 0) {
                    money[1]--;
                    money[0]--;                   
                } else if(bill == 20)  {
                    money[0] -= 3; 
                } else  if(bill == 10){
                    money[0]--; 
                }
                own += 5;
            }
        }
        return true;
    }
};