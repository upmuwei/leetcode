class Solution {
    //充分剪枝的回溯法, 回溯加哈希表去重复
    //一个是搜索过的状态不重复搜索,主要通过哈希表去重实现;另一个是可以排除的状态不去搜索,就要具体题目具体分析,看看如何排除尽可能多的状态了
public:
    set<pair<int,int>> tried;//哈希表去重

    bool isMatch(string s, string p) {
        for_each(p.begin(),p.end(),[&](char &c){ if(c=='*') ++stars;});
        return match(s, p, 0, 0);
    }
    bool match(string& s, string& p, int i, int j) {
        int length1 = s.size(), length2 = p.size();
        if(i == length1 && j == length2) {
            return true;
        }
        if(i == length1 && p[j] == '*') {
            j++;
            while(j != length2 && p[j] == '*') {
                j++;
            }
            if(j == length2) {
                return true;
            }
            return false;
        }
        if(i == length1 || j == length2) {
            return false;
        }
        if(tried.find(pair<int,int>{i,j})!=tried.end())//找过了
            return false;
        tried.insert({i,j});//没找过,记录
        while(i < length1 && j < length2) {
            if(s[i] == p[j]) {
                i++;
                j++;
            } else if(p[j] == '?') {
                i++;
                j++;
            } else if(p[j] == '*') {
                while((j + 1) < length2 && p[j + 1] == '*') {
                    j++;
                }
                bool sign = match(s, p, i + 1, j);
                if(sign) {
                    return true;
                }
                // cout << s[i] << " " << s[j] << endl;
                return match(s, p, i, j + 1);
            } else{
                break;
            }
        }
        while(j != length2 && p[j] == '*') {
            j++;
        }
        if(i == length1 && j == length2) {
            return true;
        }
        return false;
    }
};