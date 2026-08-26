link: https://leetcode.com/problems/find-the-duplicate-number/description/?envType=problem-list-v2&envId=two-pointers

The problem is very easy code is self explanatory ;)
if you don't belive in yourself who else will %_%


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> freq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] == 2) return nums[i];

        }
        return 0;
    }
};