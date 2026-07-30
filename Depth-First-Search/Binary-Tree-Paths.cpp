link: https://leetcode.com/problems/binary-tree-paths/

The problem says to find all possible paths , this automatically pushes the idea of dfs traversal.
In my solution i have reserved a vector string and a currentPath string .This ideolizes the formation of paths by adding 
{root->val} + "->" at every node , except the leaf Node

class Solution {
public:
    void find(TreeNode* root,string s,vector<string> &res){
        if(!root) return;
        if(!root->left && !root->right){
            s += to_string(root->val);
            res.push_back(s);
            return;
        }
        s+= to_string(root->val)+"->";
        find(root->left,s,res);
        find(root->right,s,res);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        find(root,s,res);
        return res;
    }
};