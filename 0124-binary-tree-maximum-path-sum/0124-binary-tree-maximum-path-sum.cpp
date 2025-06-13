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
       //3 condition
       int gotansdown=l+r+root->val;
       int anyonechild=max(l,r)+root->val;
       int only_root=root->val;
       maxSum=max(max(maxSum,gotansdown),max(anyonechild,only_root));
       return max(only_root,anyonechild); 
   }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;

    }
};