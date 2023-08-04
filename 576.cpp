class Solution {
public:
    map<tuple<int, int, int>, int> repeats;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(startRow == -1 || startColumn == -1 || startRow == m || startColumn == n) {
            return 1;
        }
        if(maxMove == 0) {
            return 0;
        }
        long count = 0;
        tuple<int, int, int> t1(maxMove - 1, startRow - 1, startColumn);
        if(repeats.find(t1) != repeats.end()) {
            count += repeats[t1];
        } else {
            int size = findPaths(m, n, maxMove - 1, startRow - 1, startColumn);
            repeats[t1] = size;
            count += size;
        }

        tuple<int, int, int> t2(maxMove - 1, startRow + 1, startColumn);
        if(repeats.find(t2) != repeats.end()) {
            count += repeats[t2];
        } else {
            int size = findPaths(m, n, maxMove - 1, startRow + 1, startColumn);
            repeats[t2] = size;
            count += size;
        }

        tuple<int, int, int> t3(maxMove - 1, startRow, startColumn - 1);
        if(repeats.find(t3) != repeats.end()) {
            count += repeats[t3];
        } else {
            int size = findPaths(m, n, maxMove - 1, startRow, startColumn - 1);
            repeats[t3] = size;
            count += size;
        }
      

        tuple<int, int, int> t4(maxMove - 1, startRow, startColumn + 1);
        if(repeats.find(t4) != repeats.end()) {
            count += repeats[t4];
        } else {
            int size = findPaths(m, n, maxMove - 1, startRow, startColumn + 1);
            repeats[t4] = size;
            count += size;
        }
        return count % (1000000007);
    }


};