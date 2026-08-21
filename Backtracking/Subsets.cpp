/* In every iteration we either take up that index value or we don't and when we have iterated the complete nums at some certain timing we add that subset created in the res
So starting from index 0 and we keep doing*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res;
       vector<int> subset;

       createSubset(nums,0,res,subset);
       return res;
    }
    void createSubset(vector<int> nums,int index,vector<vector<int>> &res,vector<int> &subset){
        if(index == nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        createSubset(nums,index+1,res,subset);

        subset.pop_back();
        createSubset(nums,index+1,res,subset);
    }
    
};