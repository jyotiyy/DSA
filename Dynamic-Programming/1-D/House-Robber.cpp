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

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        if(n == 1) return nums[0];
        dp[0] = nums[0];
       
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};