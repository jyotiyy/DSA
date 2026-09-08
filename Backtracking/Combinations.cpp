the state space is something like 
               []
        1   2   3   4
    2  3  4

    

class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int start,int n,int k,vector<int> &cur){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        for(int i = start; i <= n; i++){
            cur.push_back(i);
            backtrack(i+1,n,k,cur);
            cur.pop_back();
        }
        
       
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> cur;
        
        backtrack(1,n,k,cur);
        return res;
    }
};