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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>q;
        bool LtoR=true;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
        vector<int>temp(size);
            for(int i=0;i<size;i++){
                TreeNode*frontNode=q.front();
                q.pop();
                
                int index=LtoR?i:size-i-1;
                temp[index]=frontNode->val;
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                
            }
            LtoR=!LtoR;
                res.push_back(temp);
        }
        return res;
    }
};