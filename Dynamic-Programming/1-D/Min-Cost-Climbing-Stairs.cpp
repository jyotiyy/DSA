class Solution {
public:
    int solve(vector<int> &cost,vector<int> &dp,int i){
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i]+min(solve(cost,dp,i+1),solve(cost,dp,i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(solve(cost,dp,0),solve(cost,dp,1));
    }
};