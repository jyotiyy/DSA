class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //dp => number of arithmetic elements till index i 
        int n = nums.size();
        int dp = 0;
        int res = 0;
        for(int i = 2; i < n; i++){
            if(nums[i]-nums[i-1] == nums[i-1] -nums[i-2]){
                dp++;
            }else{
                dp=0;
            }
            res+=dp;
        }
        return res;
    }
};