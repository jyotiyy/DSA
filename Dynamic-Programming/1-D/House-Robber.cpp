link: https://leetcode.com/problems/house-robber/

This problem should be tackled using a 1-d dp 
The problem states that 2 adjacent neighbours should not be robbed at a time 
This provides 2 choices for maximizing the robbed things as curr_house+2 or curr_house+3

class Solution {
public:
    int dp[101];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int solve(vector<int> nums,int i,int n){
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = nums[i] + max(solve(nums,i+2,n),solve(nums,i+3,n));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(solve(nums,0,n-1),solve(nums,1,n-1));
    }
};