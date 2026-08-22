class Solution {
public:
    vector<int> dp;
    Solution(){
        dp.resize(50);
        fill(dp.begin(),dp.end(),-1);
    }
    int climbStairs(int n) {
        if(n == 0) return dp[n] = 0;
        if(n == 1 || n == 2) return dp[n] = n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climbStairs(n-1)+climbStairs(n-2);
    }
};