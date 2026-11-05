class Solution {
public:
    int dp[20001];
    int solve(vector<int> &nums,int i){
        if(i>=nums.size())return dp[i] = 0;
        int cur = 0;
        int index = i;
        if(dp[i] != -1)return dp[i];
        while(index < nums.size() && nums[index] == nums[i]){
            index++;
            cur += nums[i];
        }
        while(index < nums.size() && nums[index] == nums[i]+1) index++;
        return dp[i] = max(cur + solve(nums,index),solve(nums,i+1));
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return solve(nums,0);
    }
};