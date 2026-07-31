link: https://leetcode.com/problems/invert-binary-tree/description/

The problem is inverting a Binary tree ,that is reversing every level nodes . What comes in mind is dfs , 
that is from the left end reversing subtree every time ;)

class Solution {
public:
    void swapp(TreeNode*root){
        if(!root) return;
        swapp(root->left);
        swapp(root->right);
        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;
        swap(root->left,root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        swapp(root);
        return root;
    }
};