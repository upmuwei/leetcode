class Solution {
public:
    string solveEquation(string equation) {
        int x = 0, left = 0, isFactor = 0, isPositive = 1, num = 0, isLeft = 1;
        for(int i = 0; i<equation.size(); i++) {
            if(isLeft) {
                if(equation[i] == 'x') {
                    if(isFactor) {
                        x += (isPositive==1?num:-num);
                        //cout << num << endl;
                        num = 0;
                    } else {
                        x += (isPositive==1?1:-1);
                      //  cout << x << endl;
                    } 
                } else if(equation[i] == '+') {
                    if(num) {
                        left += (isPositive==1?num:-num);
                    }
                    num = 0;
                    isFactor = 0;
                    isPositive = 1;
                } else if(equation[i] == '-') {
                    if(num) {
                        left += (isPositive==1?num:-num);
                    }
                    num =0;
                    isPositive = 0;
                    isFactor = 0;
                } else  if(equation[i] == '=') {
                    if(num) {
                        left += (isPositive==1?num:-num);
                        num = 0;
                    }
                    isPositive = 1;
                    isLeft = 0;
                    isFactor = 0;
                }
                else {
                    i = stringToInt(equation, i, num);
                    isFactor = 1;
                }
            } else {
                if(equation[i] == 'x') {
                    if(isFactor) {
                        x -= (isPositive==1?num:-num);
                        num = 0;
                    } else {
                        x -= (isPositive==1?1:-1);
                    } 
                } else if(equation[i] == '+') {
                    if(num) {
                        left -= (isPositive==1?num:-num);
                    }
                    num = 0;
                    isPositive = 1;
                    isFactor = 0;
                } else if(equation[i] == '-') {
                    if(num) {
                        left -= (isPositive==1?num:-num);
                    }
                    num =0;
                    isPositive = 0;
                    isFactor = 0;
                } 
                else {
                    i = stringToInt(equation, i, num);
                    isFactor = 1;
                   // cout << num << endl;
                }
            }
        }
        if(num) {
            left -= (isPositive==1?num:-num);
        }
        //cout << x << " " << left << endl;
        if(x == 0 && left == 0) {
            return "Infinite solutions";
        } else if(x == 0) {
            return "No solution";
        }else {
            return "x=" + to_string(-left/x);
        }
    }

    int stringToInt(string equation, int index, int& num) {
        int length = equation.size();
        while(index < length && equation[index] >= '0' && equation[index] <= '9') {
            num = num * 10 + equation[index] - '0'; 
            index++;
        }
        return --index;
    }   
};