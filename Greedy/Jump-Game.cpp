At every step we find the max reach in case < i means unreachable point 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxreach = 0;
        for(int i = 0; i < n; i++){
            if(maxreach < i) return false;
            maxreach = max(maxreach,nums[i]+i);
            
        }
        return true;
    }
};