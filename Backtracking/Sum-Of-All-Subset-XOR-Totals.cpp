class Solution {
public:
    int n;
    int sum = 0;
    void dfs(int i,vector<int>& nums,int curr){
        if(i == n){
            sum += curr;
            return;
        }
        
        dfs(i+1,nums,curr^nums[i]);
        dfs(i+1,nums,curr);
    }
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        dfs(0,nums,0);
        return sum;
    }
};