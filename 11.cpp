#include <iostream>
#include <vector>


//双指针算法
using namespace std;
int main()
{
    vector<int> height;
    int n;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        height.push_back(t); 
    }    
    int max = 0;
    int begin = 0, end = height.size() - 1;
    while(begin != end) {
        int sign = 0;
        //条件运算符使用，括号、逗号后面的才参与赋值运算
        int temp = (height[begin] > height[end] ? (sign = 1, height[end]):(sign = 0, height[begin])) * (end - begin);
        if(temp > max)
            max = temp;
        if(sign) {
            end--;
        }else {
            begin++;
        }
    }
    cout << max << endl;
    return 0;
}