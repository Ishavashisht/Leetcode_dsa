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
    int searchInorder(vector<int>&inorder,int start,int end,int target){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* createTree(vector<int>&inorder,vector<int>&postorder,int &postorderIndex,int inStart,int inEnd){
        if(inStart>inEnd)return NULL;
        int ele=postorder[postorderIndex];
        postorderIndex--;

        TreeNode* root=new TreeNode(ele);
        int pos=searchInorder(inorder,inStart,inEnd,ele);

        root->right=createTree(inorder,postorder,postorderIndex,pos+1,inEnd);
        root->left=createTree(inorder,postorder,postorderIndex,inStart,pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex=postorder.size()-1;
        return createTree(inorder,postorder,postorderIndex,0,inorder.size()-1);
    }
};