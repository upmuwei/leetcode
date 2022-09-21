class Solution {
public:
    //写完就想想怎么优化
    int kSimilarity(string s1, string s2) {
        return match(s1, s2, 0); 
    }

    int match(string& s1, string& s2, int index) {
        int min = s1.size();
        if(index == s1.size() - 1) {
            return 0;
        }
        if(s1[index] == s2[index]) {
            return match(s1, s2, index + 1);
        }
        for(int i = index + 1; i < s2.size(); i++) {
            if(s2[i] == s1[index]) {
                if(s1[i] == s2[i]) {
                    continue;
                }
                swap(s2[i], s2[index]);
                int count = 1 + match(s1, s2, index+1);
                if(count < min) {
                    min = count;
                }  
                if(s1[i] == s2[i]) {
                    swap(s2[i], s2[index]); // 恢复成原模原样，回溯之前的才能查找
                    break;
                }
                swap(s2[i], s2[index]);
            }
        }
        return min;
    }
};