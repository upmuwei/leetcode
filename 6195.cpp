//平时比赛什么的无所谓，重要场合虽然没有做出来，加针对特殊用例的方法
class Solution {
public:
    int deleteString(string s) {
        set<int> looked;
        return deleteA(s, 0,looked);
    }
    
    bool isQqual(string&s, int index, int k) {
        int length = index + k;
        for(int i = index; i < length; i++) {
            if(s[i] != s[i + k]) {
                return false;
            }
        }
        return true;
    }
    int deleteA(string& s, int index, set<int>& looked) {
        if(index >= s.size()) {
            return 0;
        }
        int max = 1;
        for(int i = 1; i <= (s.size() - index)/2; i++) {
            //对呀，isQual很浪费时间的,应该在之前判断，蠢猪，你咋比较之后判断了，看清怎么优化
            if(looked.count(index + i)==0&&isQqual(s, index, i)) {
                looked.insert(index + i);
                int count = deleteA(s, index + i, looked);
                if(count >= max) {
                    max = count + 1;
                }
            }
        }
        return max;
    }
};