#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
//排序加双指针
int main()
{
   
    int t[]  = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> nums(t, t + 6); //通过数组给vector进行赋值
    vector<vector<int>> result;
    if(nums.size() < 3) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int copy_a = 1, copy_b = 10001, copy_c = 10001;
    int length = nums.size();
    for(int a = 0; a < length; a++) {
        if(nums[a] > 0) {
            break;
        }
        if(nums[a] == copy_a) {
            continue;
        }
        copy_a = nums[a];
        int b = a + 1, c = length -1;
        while(b < c) {
            int t = nums[a] + nums[b] + nums[c];
            if(t == 0) {
                vector<int> temp({nums[a], nums[b], nums[c]});
                result.push_back(temp);
                b++;
                while(b < c &&nums[b] == nums[b - 1]) {
                   b++;
                }
                c--;
                while(b < c &&nums[c] == nums[c + 1]) {
                    c--;
                }
            } else if(t > 0) {
                c--;
                while(b < c &&nums[c] == nums[c + 1]) {
                    c--;
                }
            } else {
                b++;
                while(b < c &&nums[b] == nums[b - 1]) {
                   b++;
                }
            }
        }
    }

    return 0;
}