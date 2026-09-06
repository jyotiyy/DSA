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
        if(sum > t || i == n) return;
        curr.push_back(cand[i]);
        solve(i+1,sum+cand[i],cand,t);
        curr.pop_back();
        int j = i+1;
        while(j < n && cand[j] == cand[i])j++;
        solve(j,sum,cand,t);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        // for(int i = 1; i < n; i++){
        //     if(candidates[i] == candidates[i-1]){
        //         candidates.erase(candidates.begin()+i);
        //     }
        // }
        solve(0,0,candidates,target);
        return res;
    }
};