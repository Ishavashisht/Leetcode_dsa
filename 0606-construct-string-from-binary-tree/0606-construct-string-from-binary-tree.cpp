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
  string buildstring(TreeNode*node){
    if(node==nullptr)return "";
    string res=to_string(node->val);
    if(node->left || node->right){
        res+="("+buildstring(node->left)+")";

    }
    if(node->right){
        res+="("+buildstring(node->right)+")";
    }
    return res;
  }
    string tree2str(TreeNode* root) {
        return buildstring(root);
    }
};