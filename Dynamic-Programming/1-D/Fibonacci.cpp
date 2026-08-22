class Solution {
public:
    vector<int> dp(101);
    Solution(){
        fill(dp.begin(),dp.end(),-1);
    }
    int fib(int n) {
        if(n <= 1) return dp[n] = n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fib(n-1)+fib(n-2);
    }
};