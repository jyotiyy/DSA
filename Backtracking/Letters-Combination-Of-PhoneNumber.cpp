/*This question mentions that all possible letter combinations , that means we have to use backtracking here
Now we start from index = 0 and s = ' '
                        |
                        |
                    /   |   \
                   /    |    \
                  /     |     \
                a       b      c
               /|\     /|\     /|\
               ad ae af bd be bf cd ce cf
*/

class Solution {
public:
    map<int,string> tele = {
           {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.empty()) return res;
        string s = "";
        find(digits,res,s,0);
        return res;
    }
    void find(string digits,vector<string> &res,string &s,int i){
        if(i == digits.size()){
            res.push_back(s);
            return;
        }
        string letters = tele[digits[i]-'0'];
        for(char c: letters){
            s += c;
            find(digits,res,s,i+1);

            s.pop_back();
        }
    }

};