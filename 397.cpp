class Solution {
public:
    map<long, int> records;
    int integerReplacement(int n) {
        return (int)DFS(n);
    }

    long DFS(long n) {
        if(n == 1) {
            return 0;
        }
        if(records.find(n) != records.end()) {
            return records[n];
        }
        if(n % 2 == 0) {
            return DFS(n / 2) + 1;
        } else {
            return min(DFS(n + 1), DFS(n - 1)) + 1;
        }
    }
};