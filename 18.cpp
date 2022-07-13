#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//注意细节
int main()
{
    vector<vector<int>> results;
    vector<int> nums = {2,2,2,2,2};
    int target = 8;
    sort(nums.begin(), nums.end());
    int a = 0, b = nums.size() -1, c, d, sign = 1;
    for(int a = 0; a < nums.size() - 3; a++) {
        b = nums.size() -1;
        while(a < b) {
            c = a + 1;
            d = b - 1;
            while(c < d) {
                long t = (long)nums[a] + nums[b] + nums[c] + nums[d] - target;
                if(!t) {
                    vector<int> t;
                    t.push_back(nums[a]);
                    t.push_back(nums[c]);
                    t.push_back(nums[d]);
                   
                     t.push_back(nums[b]);
                      results.push_back(t);
                    while(c+1 < d && nums[c + 1] == nums[c]) {
                        c++;
                    }
                    while(d-1 > c && nums[d - 1] == nums[d]) {
                        d--;
                    }
                    c++;
                    d--;
                } else if(t > 0) {
                    d--;
                } else {
                    c++;
                }
            }
            while(b-1 > a && nums[b -1] == nums[b]) {
                b--;
            }
            b--;
           
        }
        while(a < nums.size() - 3 &&nums[a + 1] == nums[a]) {
            a++;
        }
    }
    cout << results.size() << endl;
    return 0;
}