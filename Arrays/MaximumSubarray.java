link: https://leetcode.com/problems/maximum-subarray/

The sole idea is Kadanes algorithm** .As per this we maintain a curSum 
and set it to 0 when it becomes negative as that cumulativeSum will depreceate the 
upcoming additions :)
My one of the favourite algorithm as it teaches when you observe a constant decreasing curve 
in any aspect to your life reset it from zero ;)

class Solution {
    public int maxSubArray(int[] nums) {
        int curSum = 0;
        int maxSum = Integer.MIN_VALUE;
        
        for(int i = 0; i < nums.length; i++){
            curSum += nums[i];
            maxSum = Integer.max(maxSum,curSum);
            if(curSum < 0){
                curSum =0;
            }
        }
        return maxSum;
    }
}