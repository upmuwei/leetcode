class Solution {
public:
    //提醒自己看清题
    //注意两个数&还有等于0的情况
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i = 0, length = asteroids.size();
        int j = i, k = i + 1;
        while(i>=0&&k < asteroids.size()) {
            while(k < asteroids.size()&& j >=0 && asteroids[j] > 0 && asteroids[k] < 0) {
            int t = asteroids[j] + asteroids[k];
            if(t == 0) {
                asteroids.erase(asteroids.begin() + j);
                asteroids.erase(asteroids.begin() + j);
                k = j;
                j--;;
            } else if(t > 0) {
                asteroids.erase(asteroids.begin() + k);    
            } else {
                asteroids.erase(asteroids.begin() + j);
                k = j;
                j--;
            }
        }
        j++;
        k++;
        }
        
        return asteroids;
    }
};