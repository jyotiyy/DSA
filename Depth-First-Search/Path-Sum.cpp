link: https://leetcode.com/problems/path-sum/description/

Restating the problem the target was to find if there exists a path from the root to leaf whose node sum will be equal to the targtSum

We must emphasize on the phrase "Root->leaf" , which clarifies intermediatory paths are not considered 
Since every node has 2 childrens left,right . This naturally makes us to beleive in dfs traversal.
For this purpose i will pass a running sum variable which keeps track of curr sum till a point in the path . 
Ones it finds that the given node is the leaf node through the condition root->left == nullptr && root->right == nullptr
it will check if the sum calculated across that path equals the targetSum and returns the output 

Explaining the base case and recursive calls 
Analysing the complexity we realise all nodes are iterated ones 
TC -> O(n)
SC -> O(h)


class Solution {
public:
    bool has(TreeNode*root,int i,int t){
        if(!root) return false;
        i+=root->val;
        if(root->left == nullptr && root->right == nullptr){
            return i == t;
        }
        
        return has(root->left,i,t) || has(root->right,i,t);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return has(root,0,targetSum);
    }
};