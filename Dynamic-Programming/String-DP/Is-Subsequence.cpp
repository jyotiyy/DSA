The problem statement simply asks if s is a subsequence of t 

This is two pointer although

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int j = 0;
       
        for(int i= 0; i < m; i++){
            if(t[i] == s[j]) j++;
        }
        return j == n;
    }
};

class Solution {
public:
    //dp[i][j] = 1 means till index j of s the characters are a part of t till ith index
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        s = '!'+s; //s = 1 indexed
        t = '!'+t;

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i <= m; i++){
            dp[i][0] = 1; //an empty in string s is a subsequnce of t
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(t[i] == s[j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n] == 1;

    }
};