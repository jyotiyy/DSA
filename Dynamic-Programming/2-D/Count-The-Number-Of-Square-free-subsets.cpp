class Solution {
public:
    const int mod = 1e9 + 7;
    int squareFreeSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes = {
            2,3,5,7,11,
            13,17,19,23,29
        };
        //dp[i][mask] = number of ways with the masked primes choosen till index i
        vector<vector<long long>> dp(
            n+1, 
            vector<long long>(1 << 10,0)
        );
        dp[0][0] = 1;
        //choosing nothing
        for(int i = 0; i < n; i++){
            int x = nums[i];
            //not take x
            for(int mask = 0; mask < 1 << 10; mask++){
                dp[i+1][mask] += dp[i][mask];
            }
            //find primes of x;
            int xmask = 0;
            bool valid = true;
            for(int j = 0; j < 10; j++){
                int p = primes[j];
                if(x%(p*p) == 0){
                    valid = false;
                    break;
                }
                if(x%p == 0){
                    xmask |= (1 << j);
                }
            }

            if(!valid) continue;
            //take x
            for(int mask = 0; mask < (1 << 10); mask++){
                if(mask & xmask) continue;
                dp[i+1][mask|xmask] = (dp[i+1][mask|xmask]+dp[i][mask])%mod;
            }

        }
        long long res = 0;
        for(int i = 0; i < (1 << 10); i++){
            res = (res+dp[n][i])%mod;
        }
        return (res -1 + mod)%mod;
        

    }
};