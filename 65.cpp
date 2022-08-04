class Solution {
public:
    bool isNumber(string s) {
        bool decimal = false;
        bool negative = false;
        bool isNumber = false;
        int index = 1;
        if(s[0] == '-' || s[0] == '+') {
            if(s.size() == 1)
                return false;
            negative = true;
        }
        else if(s[0] == '.') {
            if(s.size() == 1)
                return false;
            decimal = true;
        }
        else if(s[0] < '0' || s[0] > '9') {
            return false;
        }
        if(negative == false && decimal == false) {
            isNumber = true;
        }
        negative = false;
      
        while(index < s.size() && (s[index] != 'e' && s[index] != 'E')) {
            if(s[index] == '.') {
                if(decimal) {
                    
                    return false;
                } else {
                    decimal = true;
                }
            }else  if(s[index] < '0' || s[index] > '9') {
                return false;
            } else {
                isNumber = true;
            }
            index++;
        }
        if(!isNumber) {
            return false;
        }
        if(index < s.size()) {
            index++;
            if(index == s.size()) {
                return false;
            }
            isNumber = false;
            while(index < s.size()) {
                if(s[index] == '-' || s[index] == '+') {
                    if(negative) {
                        return false;
                    } 
                    negative = true;
                } else if(s[index] < '0' || s[index] > '9') {
                    return false;
                } else {
                    negative = true;
                    isNumber = true;
                }
                index++;
            }
            if(!isNumber) {
                return false;
            }
        }
        return true;
    }
};