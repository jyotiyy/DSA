take/skip with memo , 
but this gave 65/66 T_T wow 
bottom-up is my friend top-down is ewww

class Solution {
public:
//take or skip
    int solve(int i,int j,string s,string t,vector<vector<int>>&memo){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        int notTake = solve(i+1,j,s,t,memo);
        int take = 0;
        if(s[i] == t[j]){
            take = solve(i+1,j+1,s,t,memo);
        }
        return memo[i][j] = take+notTake;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return solve(0,0,s,t,memo);
    }
};


class Solution {
public:
//take or skip
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        //if t is empty only one way to choose that 
        //if we consider dp[i][j] = match sequence of s[i...] and t[j...]
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];

        
    }
};

class Solution {
public:
//take or skip
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        //if t is empty only one way to choose that 
        //if we consider dp[i][j] = match sequence of s[...i] and t[...j]
        for(int i = 0; i <= n; i++){
            dp[i][m] = 1;
        }
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j >=0; j--){
                dp[i][j] = dp[i+1][j] ;//not take
                if(s[i] == t[j]){
                    dp[i][j]+=dp[i+1][j+1]; //take
                }
            }
        }
        return dp[0][0];

        
    }
};