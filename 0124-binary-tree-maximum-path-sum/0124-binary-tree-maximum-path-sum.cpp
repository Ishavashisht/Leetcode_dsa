/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int maxSum=0;
    int solve(TreeNode*root){
        if(!root)return 0;
        int l=max(0,solve(root->left));
        int r=max(0,solve(root->right));
        int allnodeSum=l+r+root->val;
       
        maxSum=max(maxSum,allnodeSum);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};