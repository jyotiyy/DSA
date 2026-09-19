class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int pref = 0;
        for(int i = 0; i < nums.size(); i++){
            if(pref == sum-nums[i]-pref)return i;
            pref += nums[i];
            
        }
        return -1;
    }
};