0-1 Knapsack

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<int>> dp(101,vector<int>(101,0));
        //dp[i][j] -> maximum number of strings that can be taken such that ones <= j and zeroes <= i
        for(string &str: strs){
            int c0 = ranges::count(str,'0');
            int c1 = str.size()-c0;
            for(int i = m; i >= c0; i--){
                for(int j = n; j >= c1; j--){
                    dp[i][j] = max(dp[i][j], //dont take
                    1+dp[i-c0][j-c1]);   // take
                }
            }
        }
        return dp[m][n];

        
    }
};