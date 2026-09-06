class Solution {
public:
    vector<vector<int>> res;
    int n;
    void perm(int ind,vector<int> &nums){
        if(ind == n){
           res.push_back(nums);
           return;
        }
        unordered_set<int> used; //check for used at this level
        for(int j = ind; j < n; j++){
            if(used.count(nums[j]))continue;
            used.insert(nums[j]);
            swap(nums[ind],nums[j]);
            perm(ind+1,nums);
            swap(nums[ind],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        perm(0,nums);
        return res;
    }
};