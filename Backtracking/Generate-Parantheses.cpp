class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        auto dfs = [&](auto&&dfs,string s,int open,int close){
            if(s.length() == n*2){
                res.push_back(s);
                return;
            }
            if(open < n){
                dfs(dfs,s+"(",open+1,close);
            }
            if(close < open){
                dfs(dfs,s+")",open,close+1);
            }
        };
        string s;
        dfs(dfs,s,0,0);
        return res;
    }
};