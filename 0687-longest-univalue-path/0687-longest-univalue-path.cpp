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
int maxLen=0;
int dfs(TreeNode*node){  //dfs(5)
if(!node)return 0;
int left=dfs(node->left); 
int right=dfs(node->right);  
int leftPath=0,rightPath=0;
if(node->left && node->left->val==node->val){
leftPath=left+1;
}
if(node->right && node->right->val==node->val){
rightPath=right+1; //rightPath=0+1=1//+1=2 
}
maxLen=max(maxLen,leftPath+rightPath);//1  =>2 
return max(leftPath,rightPath);
}

    int longestUnivaluePath(TreeNode* root) {
      dfs(root);
return maxLen;  
    }
};