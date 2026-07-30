link: https://leetcode.com/problems/sum-of-left-leaves

I solve this problem using DFS traversal, where i traverse all the possible paths from root to tree.
For checking of left leaf nodes , I add a condition named 
root->left && !root->left->left && !root->left->right (This tells root->left) is a left leaf and should be added into sum 
Moreover a frequent mistake that can be done is adding a return after the left leaf condition which halts check for the 
right side . :(

class Solution {
public:
    void find(TreeNode* root,int &sum){
        if(!root) return;
        
        if(root->left &&
         !root->left->left &&
         !root->left->right){
            sum += root->left->val; 
        }
        find(root->left,sum);
        find(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int tot = 0;
        find(root,tot);
        return tot;
    }
};