link: https://leetcode.com/problems/maximum-product-subarray/description/
The intution of kadane(which was used for maximum sum of subarray ) could generate here 
when we hit this problem . However we must understand that using it will be problematic 
as negative numbers not always decreases the cumulative product .
So we come up with a method where we take note of the extreme small and extreme large 
and make decisions . Somewhere in middle we meet the largest product and keep that result in res 
to return it later on 


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxProd(n,INT_MIN);
        vector<int> minProd(n,INT_MAX);
        maxProd[0] = nums[0];
        minProd[0] = nums[0];
        int res = nums[0];
        for(int i = 1; i < n; i++){
            maxProd[i] = max(nums[i],max(nums[i]*maxProd[i-1],minProd[i-1]*nums[i]));
            minProd[i] = min(nums[i],min(nums[i]*maxProd[i-1],minProd[i-1]*nums[i]));
            res = max(res,maxProd[i]);
        }
        return res;
    }
};