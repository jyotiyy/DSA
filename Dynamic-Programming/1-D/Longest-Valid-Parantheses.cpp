class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        int res = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == ')'){

                // () case
                if(s[i-1] == '('){
                    dp[i] = 2;
                    if(i>=2){
                        dp[i]+=dp[i-2];
                    }
                }else{ // (...) case
                    int prev = i-dp[i-1]-1;
                    if(prev>=0 && s[prev] == '('){
                        dp[i]=dp[i-1]+2;
                        if(prev>=1){
                            dp[i]+=dp[prev-1];
                        }
                    }
                }
            }
            res = max(res,dp[i]);
        }

        return res;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0;
        int close = 0;
        int res = 0;
        for(char c: s){
            if(c == '(')open++;
            else close++;
            if(close>open){
                close = 0;
                open = 0;
            }
            if(open == close){
                res = max(res,min(open,close)*2);
            }
        }
        open = close = 0;
        for(int i = s.size()-1; i >= 0; i--){
            char c = s[i];
            if(c == '(')open++;
            else close++;
            if(open>close){
                close = 0;
                open = 0;
            }
            
            if(open == close){
                res = max(res,min(open,close)*2);
            }
            
        }
        return res;
    }
};