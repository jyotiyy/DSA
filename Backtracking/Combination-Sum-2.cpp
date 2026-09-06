class Solution {
public:
    int n;
    vector<int> curr;
    vector<vector<int>> res;
    
    void solve(int i,int sum,vector<int> &cand,int t){
        if(sum == t){
            res.push_back(curr);
            return;
        }
        if(sum > t) return;
        for(int j = i; j < n; j++){
            if(j > i && cand[j] == cand[j-1]){
                continue;
            }
            curr.push_back(cand[j]);
            solve(j+1,sum+cand[j],cand,t);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(0,0,candidates,target);
        return res;
    }
};