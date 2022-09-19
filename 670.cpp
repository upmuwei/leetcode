class Solution {
public:
    int maximumSwap(int num) {
        string t = to_string(num);
        for(int i = 0; i < t.size(); i++) {
            int k = i;
            for(int j = i + 1; j < t.size(); j++) {
                //注意细节，换后面的
                if(t[j] >= t[k]) {
                    k = j;
                }
            }
            if(t[k] > t[i]) {
                swap(t[k], t[i]);
                break;
            }
        }
        return stoi(t);    
    }
};