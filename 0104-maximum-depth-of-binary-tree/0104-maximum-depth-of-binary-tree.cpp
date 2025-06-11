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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int maximumDepth=0;
        int maxleft=0,maxright=0;
        if(root->left!=nullptr){
            maxleft+=maxDepth(root->left);
        }
        if(root->right!=nullptr){
            maxright+=maxDepth(root->right);
        }
        maximumDepth=1+max(maxleft,maxright);
        return maximumDepth;

    }
};