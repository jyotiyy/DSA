link: https://leetcode.com/problems/sum-root-to-leaf-numbers

I solve this problem using a Depth-First Search (DFS). Along every root-to-leaf path,
I maintain a string representing the number formed by the node values seen so far. At each node,
I append its value to the current string. When I reach a leaf node, the complete root-to-leaf number has been formed
, so I convert the string into an integer using stol() and add it to the final sum. Since each node is visited 
exactly once, the overall time complexity is O(n), where n is the number of nodes. However, because
I'm passing strings recursively and creating new copies, the effective complexity is O(n × h) in the worst case 
(h = tree height), with O(h) recursion stack space plus the string storage. 
A more optimal approach is to maintain the number as an integer (curr = curr * 10 + root->val)
instead of a string, which avoids string copying and conversions while still achieving O(n) time.


class Solution {
public:
    void find(TreeNode* root,string x,long long &sum){
        if(!root) return;
        if(!root->left && !root->right){
            x+= to_string(root->val);
            sum += stol(x);
            return;
        }
        x += to_string(root->val);
        find(root->left,x,sum);
        find(root->right,x,sum);
        return;
        
    }
    int sumNumbers(TreeNode* root) {
        long long sum = 0;
        string curr;
        find(root,curr,sum);
        return sum;
    }
};