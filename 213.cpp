class Solution {
public:
/*
环状排列意味着第一个房子和最后一个房子中只能选择一个偷窃，
因此可以把此环状排列房间问题约化为两个单排排列房间子问题(198)：
在不偷窃第一个房子的情况下（即 nums[1:]），最大金额是p1；
在不偷窃最后一个房子的情况下（即 nums[:n-1]），最大金额是p2。
综合偷窃最大金额： 为以上两种情况的较大值，即 max(p1,p2)。
*/
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n == 1) return nums[0];
        int Max1 = rob1(nums,0,n-1);//不偷窃最后一个房子
        int Max2 = rob1(nums,1,n);//不偷窃第一个房子
        return max(Max1,Max2);
    }
    int rob1(vector<int>& nums,int start,int end){
        /*
        动态转移方程是：
        f(n)=max(nums[n]+f(n-2),f(n-1))
        prevMax:f(k-2)
        currMax:f(k-1)
        x:Ak
        */
        int prevMax = 0;
        int currMax = 0;
        for(int i=start;i<end;i++){
            int temp = currMax;
            currMax = max(nums[i]+prevMax, currMax);
            prevMax = temp;
        }
        return currMax;
    }
};