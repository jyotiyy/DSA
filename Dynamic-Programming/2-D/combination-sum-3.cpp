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

class Solution {
public:
    vector<int> glob = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<vector<int>>> dp(n+1);
        dp[0].push_back({});
        for(int x: glob){
            for(int s = n; s>= x; s--){
                for(auto comb: dp[s-x]){
                    if(comb.size()>=k)continue;
                    comb.push_back(x);
                    
                    dp[s].push_back(comb);
                
                }
            }
        }
        vector<vector<int>> fin;
        for(auto &comb: dp[n]){
            if(comb.size() == k){
                fin.push_back(comb);
            }
        }
        return fin;
        
    }
};