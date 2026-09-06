class Solution {
public:
    int n;
    vector<vector<int>> res;
    int tar;
    void find(int i,vector<int> &cur,vector<int> &cand){
        int sum = accumulate(cur.begin(),cur.end(),0);
        if(sum == tar){
            res.push_back(cur);
            return;
        }
        if(i == n || sum > tar){
            return;
        }
        cur.push_back(cand[i]);
        find(i,cur,cand);
        cur.pop_back();
        find(i+1,cur,cand);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       n = candidates.size();
       tar = target;
       vector<int> curr;
       find(0,curr,candidates);
       return res;

    }
};