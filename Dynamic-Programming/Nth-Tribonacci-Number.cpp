link: https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int find(int n,vector<int> &dp){
        if(dp[n]!=-1) return dp[n];
        if(n<=1) return n;
        if(n == 2) return 1;
        
        return dp[n] = find(n-1,dp)+find(n-2,dp)+find(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return find(n,dp);
    }
};