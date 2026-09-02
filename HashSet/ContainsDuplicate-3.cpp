the idea here is to only store elements with the i-indexdiff and then checking of any lowebound exists 
we only check at last indexDiff elements from an index i , as this eventually covers all combinations 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        //basically finding the lower bound for every indexDiff elements 
        //if there is element in range [x-valueDiff,x+valueDiff]

        set<long long> s;
        for(int i = 0; i < nums.size(); i++){
            long long x = nums[i];
            auto it = s.lower_bound((long long)(x-valueDiff));
            if(it!= s.end() && *it <= (long long)(x+valueDiff)) return true;
            s.insert(x);
            if(i >= indexDiff){
                s.erase(nums[i-indexDiff]);
            }
        }
        return false;
    }
};