#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    void startGame(vector<int> list, int n, int m) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        for(int cell : list) {
            board[(cell - 1) / n ][(cell - 1) % n] = 1;
        }
        for(int i = 0; i < m; i++) {
            gameOfLife(board);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j]) {
                    cout << i * n + j + 1 << " ";
                }
            }
        }
        cout << endl;
    }   

    void gameOfLife(std::vector<std::vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 计算与board[i][j]相邻的活细胞数量
                int lives = liveNeighbors(board, m, n, i, j);

                // 如果当前位置为活细胞，且相邻活细胞数量为2个或者3个，则下一状态仍为活细胞
                if (board[i][j] == 1 && (lives == 2 || lives == 3)) {
                    board[i][j] = 3;
                }

                // 如果当前位置为死细胞，且相邻活细胞数量为3个，则下一状态为活细胞
                if (board[i][j] == 0 && lives == 3) {
                    board[i][j] = 2;
                }
            }
        }

        // 更新细胞状态
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }

private:
    int liveNeighbors(const std::vector<std::vector<int>>& board, int m, int n, int i, int j) {
        int lives = 0;
        for (int x = std::max(i - 1, 0); x <= std::min(i + 1, m - 1); x++) {
            for (int y = std::max(j - 1, 0); y <= std::min(j + 1, n - 1); y++) {
                lives += board[x][y] & 1;
            }
        }
        lives -= board[i][j] & 1;
        return lives;
    }
};

int main() {
    Solution solution;
    vector<int> list({1, 2, 3, 4 ,5});
    int n = 5, m = 1;
    solution.startGame(list, n, m);

    return 0;
}