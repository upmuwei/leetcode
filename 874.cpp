class Solution {
    set<pair<int, int>> obstacleSet;
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for(auto obstacle : obstacles) {
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));
        }
        int x = 0, y = 0, max = 0;
        int direction = 1; //3:南， 2：东，0：西
        int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int command : commands) {
            if(command == -1) {
                direction = (direction + 1) % 4;
            } else if(command == -2) {
                direction = (direction - 1 + 4) % 4;
            } else {
                for(int i = 0; i < command; i++) {
                    x += move[direction][0];
                    y += move[direction][1];
                    if(obstacleSet.find({x, y}) != obstacleSet.end()) {
                        x -= move[direction][0];
                        y -= move[direction][1];
                        break;
                    }
                }
                int t = x * x + y * y;
                if(t > max) {
                    max = t;
                }
            }
        }
        return max;
    }
};