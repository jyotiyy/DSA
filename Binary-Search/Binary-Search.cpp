/*  Since the Problem Statement mentions clearly **sorted in ascending order** binary search is clearly applicable for this problem . Also the O(log n) is explicitly mentioned. Now here we maintain an inclusive range
[l,h] and for every iteration we find the mid using l+(h-l)/2 Using this instead of (l+h)/2 prevents the overflow issue .Moreover in every upcoming interation we divide the array into half based on the condition 
if the mth position element is greater than the target we move towards left half , and if it is lesser than the target we move towards right half .Also each iteration halves the search space so the time complexity is O(log n) and the space complexit is O(n)*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;
        while(l <= h){
            int m = l + (h-l)/2; // To eliminate the overflow condition 
            if(nums[m] == target) return m;
            if(nums[m] > target){
                h = m-1;
            }else{
                l = m+1;
            }
        }
        return -1;
    }
};