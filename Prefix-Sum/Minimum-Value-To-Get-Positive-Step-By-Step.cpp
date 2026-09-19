class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum < 0){
                res = min(res,sum);
            }
        }
        return (res==INT_MAX)? 1:abs(res)+1;
    }
};