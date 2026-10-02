class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+1,0);
        dp[0] = 1;
        for(int s = 1; s <= target; s++){
            for(int x: nums){
                if(s>=x){
                    if(dp[s] >= LLONG_MAX-dp[s-x]){
                        dp[s] = LLONG_MAX;
                    }else{
                        dp[s] +=dp[s-x];
                    }
                }
            }
        }
        return (int)dp[target];
    }
};
