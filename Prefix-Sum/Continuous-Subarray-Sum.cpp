class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int pref = 0;
        mp[0] = -1;
        //If two numbers have the same remainder when divided by k, their difference is divisible by k.
        for(int i = 0; i < nums.size(); i++){
            pref += nums[i];
            int rem = pref%k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2)return true;
            }else{
                mp[rem] = i;
            }
        }
        return false;
    }
};