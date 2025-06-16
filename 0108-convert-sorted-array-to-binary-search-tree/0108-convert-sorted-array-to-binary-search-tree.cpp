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
    TreeNode* sortedArrayToBST(vector<int> nums) {
        if(nums.size()==0){
            return NULL;
        }
        if (nums.size() == 1) {
            TreeNode* nn = new TreeNode(nums[0]);
            return nn;
        }
        if (nums.size() == 2) {
            TreeNode* nn1 = new TreeNode(nums[0]);
            TreeNode* nn2 = new TreeNode(nums[1]);
            nn1->right = nn2;
            return nn1;
        }
        int mid = nums.size() / 2;
        TreeNode* leftTree = sortedArrayToBST(vector<int>(nums.begin(),nums.begin()+mid));
        TreeNode* rightTree = sortedArrayToBST(vector<int>(nums.begin()+mid+1,nums.end()));
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=leftTree;
        root->right=rightTree;
        return root;
    }
};