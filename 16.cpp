#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//双指针法
int main() {
    int n;
    int target = 1, i = 0;
    int result = 10000;
    int a[1001];
    cin >> n;
    while(i < n) {
        cin >> a[i];
        i++;
    } 
    vector<int> nums(a, a + n);
    sort(nums.begin(), nums.end());
    int length = nums.size();
    for(int i = 0; i < length; i++) {
        int j = i + 1;
        int k = length - 1;
        while(j < k) {   
            int t = nums[i] + nums[j] + nums[k] - target;
            if(abs(t) < abs(result)) {
                result = t;
            }
            if(t == 0) {
                break;
            }else if( t > 0) {
                k--;
            }else {
                j++;
            }
        }
        if(j != k) {
            break;
        }
    }
    cout << result + target << endl;
    return 0;
}