link: https://leetcode.com/problems/path-sum-ii/

Restating the problem , it asks to find the sequenced paths whose overall sum is equal to the targetSum. 
Its natural to travel across all the routes therefore DFS traversal. maintaing a global 2d vector where the paths get added 

TC -> O(n)
SC -> O(n**2)


class Solution {
public:
    vector<vector<int>> res;
    void find(TreeNode*root,vector<int> v,int tar){
        if(!root) return;
        tar-=root->val;
        v.push_back(root->val);
        if(!root->left && !root->right){
            if(tar == 0) res.push_back(v);
            return;
        }
        find(root->left,v,tar);
        find(root->right,v,tar);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        find(root,path,targetSum);
        return res;
    }
};
