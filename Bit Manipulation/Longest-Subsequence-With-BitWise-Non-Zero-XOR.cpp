link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/

My approach is based on XOR idea .If the whole vector constitutes to a non-zero xor value, that 
makes it obvious to declare the answer as length of the array. However for the case where the sum is 
zero removing one number from the complete list will again make the xor non-zero. 
However if there are no non-zero elements in the array the answer will be 0, as it will not be possible
to get any subarray with cumulative xor value 0
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int tot = 0;
        int nonZero = 0;
        for(int r = 0; r < nums.size(); r++){
            tot ^= nums[r];
            nonZero |= nums[r] > 0;
        }
        return nonZero* (nums.size()-!tot);
        
    }
};