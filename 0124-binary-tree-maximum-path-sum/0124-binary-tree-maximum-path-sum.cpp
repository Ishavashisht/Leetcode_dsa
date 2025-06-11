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
        int l=solve(root->left);
        int r=solve(root->right);
        int allnodeSum=l+r+root->val;
        int anyonechildplusroot=max(l,r)+root->val;
        int onlyroot=root->val;
        maxSum=max(maxSum,allnodeSum);
        return max(onlyroot, anyonechildplusroot);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};