class Solution {
public:
    int maxDiff(vector<int> &nums, int left,int right){
        if(left == right) return nums[left];
        int scoreByLeft = nums[left] - maxDiff(nums,left+1,right);
        int scoreByRight = nums[right] - maxDiff(nums,left,right-1);
        return max(scoreByLeft,scoreByRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return maxDiff(nums,0,n-1) >= 0;

    }
};

class Solution {
public:

    int maxDiff(vector<int> &nums, int left,int right,vector<vector<int>> dp){
        if(left == right) return nums[left];
        if(dp[left][right] != -1) return dp[left][right];
        int scoreByLeft = nums[left] - maxDiff(nums,left+1,right,dp);
        int scoreByRight = nums[right] - maxDiff(nums,left,right-1,dp);
        return dp[left][right] = max(scoreByLeft,scoreByRight);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return maxDiff(nums,0,n-1,dp) >= 0;

    }
};

class Solution {
public:

    
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }

        for(int diff = 1; diff < n; diff++){
            for(int left = 0; left < n-diff; left++){
                int right = left+diff;
                dp[left][right] = max(nums[left]-dp[left+1][right],nums[right]-dp[left][right-1]);
            }
        }
        return dp[0][n-1] >= 0;

    }
};