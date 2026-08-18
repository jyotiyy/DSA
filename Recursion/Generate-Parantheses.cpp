link: https://leetcode.com/problems/generate-parentheses/
The idea is simple if length of current making string is 2*n (n "(" and n ")") add it to res and return
if open < n that means we need to add "(" and open+1
if close < open means we need to add a ")" and close+1



class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        helper("",0,0,n);
        return res;
    }
    void helper(string s,int open,int close,int n){
        if(s.length() == n*2){
            res.push_back(s);
            return;
        }
        if(open < n){
            helper(s+"(",open+1,close,n);
        }
        if(close < open){
            helper(s+")",open,close+1,n);
        }
    }
};