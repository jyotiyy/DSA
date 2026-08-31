link: https://leetcode.com/problems/decode-ways/

The idea is simple either take 2 digits or 1 digit 


class Solution {
public:
    //dp[i] = number of ways to make the string i...n
    //dp[n] = 1 , ways to decode an empty string is 1
    // otherwise dp[i] = dp[i+1](take one digit)
    //or if s[i] s[i+1] between 10 to 26 then dp[i]+=dp[i+2]

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
            }else{
                dp[i] = dp[i+1];
                int two = stoi(s.substr(i,2));
                if(two >= 10 && two <= 26){
                    dp[i]+=dp[i+2];
                }
            }
        }
        return dp[0];
    }
};
