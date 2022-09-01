class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited;
        for(int i = 0; i < board.size(); i++) {
            vector<bool> t(board[i].size(), false);
            visited.push_back(t);
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(word[0] == board[i][j]) {
                    visited[i][j] = true;
                    if(match(visited, board, word, 1, i, j)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    bool match(vector<vector<bool>> &visited, vector<vector<char>>& board, string& word, int index, int i, int j) {
        if(index == word.size()) {
            return true;
        }
        if(i-1 >= 0 && visited[i -1][j] == false &&board[i - 1][j] == word[index]) {
            visited[i -1][j] = true;
            if(match(visited, board, word, index + 1, i -1, j)) {
                return true;
            }
            visited[i-1][j] = false;
        }
        if(i+ 1 < visited.size() && visited[i + 1][j] == false &&board[i + 1][j] == word[index]) {
            visited[i + 1][j] = true;
            if(match(visited, board, word, index + 1, i + 1, j)) {
                return true;
            }
            visited[i+1][j] = false;
        }
        if(j-1 >= 0 && visited[i][j - 1] == false &&board[i][j - 1] == word[index]) {
            visited[i][j - 1] = true;
            if(match(visited, board, word, index + 1, i, j - 1)) {
                return true;
            }
            visited[i][j - 1] = false;
        }
        if(j+ 1 < visited[i].size() && visited[i][j + 1] == false &&board[i][j + 1] == word[index]) {
            visited[i][j + 1] = true;
            if(match(visited, board, word, index + 1, i, j + 1)) {
                return true;
            }
            visited[i][j + 1] = false;
        }
        return false;
    }
};