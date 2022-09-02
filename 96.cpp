class Solution {
public:
    int numTrees(int n) {
        map<int, int> index;
        index[0] = 1;
        index[1] = 1;
        index[2] = 2;
        return match(index, n);
    }

    int match(map<int, int> &index, int n) {
        if(index[n] != 0) {
            return index[n];
        }
        int count = 0;
        for(int i = 1; i <= n; i++) {
            count += match(index, i - 1) * match(index, n - i);
        }
        index[n] = count;
        return count;
    }   
};