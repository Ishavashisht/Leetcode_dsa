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
    int searchInInorder(vector<int>&inorder,int start,int end,int target){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* createTree(vector<int>&preorder,vector<int>&inorder,int &preIndex,int inorderStart,int inorderEnd){
if(preIndex>=preorder.size() || inorderStart>inorderEnd){
    return NULL;
}

int ele=preorder[preIndex];
preIndex++;
TreeNode* newRoot=new TreeNode(ele);

int pos=searchInInorder(inorder,inorderStart,inorderEnd,ele);

newRoot->left=createTree(preorder,inorder,preIndex,inorderStart,pos-1);
newRoot->right=createTree(preorder,inorder,preIndex,pos+1,inorderEnd);

return newRoot;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        return createTree(preorder,inorder,preIndex,0,inorder.size()-1);
    }
};