class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<char> t1, t2; 
        int count1 = 0, count2 = 0;
        int result = 0;
        count1 = toBinary(t1, num1);
        count2 = toBinary(t2, num2);
        if(count1 == count2) {
            result = num1;
        } else if(count1 < count2) {
            result = num1;
            int i = 0;
            for(; i < t1.size(); i++){
                if(t1[i] == '0') {
                    result += pow(2, i);
                    count1++;
                }
                if(count1 == count2) {
                    break;
                }
            }
            while(count1 < count2) {
                result += pow(2, i);
                i++;
                count1++;
            }
        } else {
            result = num1;
            int i = 0;
            for(int i =0; i < t1.size(); i++) {
                if(t1[i] == '1') {
                    result -= pow(2, i);
                    count1--;
                }
                if(count1 == count2) {
                    break;
                }
            }
        }
        return result;
    }
    
    int toBinary(vector<char>& t, int num) {
        int count = 0;
        while(num) {
            char c = num%2 + '0';
            t.push_back(c);
            if(c == '1') {
                count++;
            }
            num /= 2;
        }
        return count;
    }
    
};