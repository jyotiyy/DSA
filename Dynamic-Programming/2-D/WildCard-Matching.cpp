So the approach is when the characters are same or there is wildcard we take both characters 
and set the value as per the (i-1)th (j-1)th .However if they differ we can only pertain
the pattern if there was a * . That is either ignore (ith element of s or jth element of p)

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = true;
        for(int j = 1; j <= n; j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }else if((p[j-1] == '?')||(s[i-1] == p[j-1])){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];


    }
};