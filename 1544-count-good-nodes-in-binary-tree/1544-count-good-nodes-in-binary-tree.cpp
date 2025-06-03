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
int countGoodNodes(TreeNode*root,int maxSoFar){
if(!root)return 0;
int count=0;
if(root->val>=maxSoFar){
    count=1;
}
maxSoFar=max(maxSoFar,root->val);
count+=countGoodNodes(root->left,maxSoFar);
count+=countGoodNodes(root->right,maxSoFar);
return count;
}
    int goodNodes(TreeNode* root) {
     if(!root)return 0;
return  countGoodNodes(root,root->val);
       
    }
};