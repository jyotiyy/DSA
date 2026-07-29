link: https://leetcode.com/problems/integer-break/

Bottom - Up approach where we do it like this --> we take for atleast 2 size 
                         5
max(1,dp[1])max(4,dp[4])   max(2,dp[2]) ,max(3,dp[3])
and so onn at every step if we should take the element itself or the largest of previous manipulations 
         
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                int left = max(j,dp[j]);
                int right = max(i-j,dp[i-j]);
                dp[i] = max(dp[i],left*right);
            }
        }
        return dp[n];
    }
};