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
// //step1 we will find all possible tree first
// vector<TreeNode*>allPossibleBST(int start,int end){
// //2 base case
// if(start>end)return {0};
// if(start==end) return {new TreeNode(start)};
// vector<TreeNode*>ans;
// //we will then find all the possible trees from left and right 
// for(int i=0;i<=end;i++){
// vector<TreeNode*>left=allPossibleBST(start,i-1);
// vector<TreeNode*>right=allPossibleBST(i+1,end);
// //we will now iterate all the possible tree in left and right 
// for(int j=0;j<left.size();j++){
//     for(int k=0;k<right.size();k++){
//         TreeNode* root=new TreeNode(i);
//         root->left=left[j];
//         root->right=right[k];
//         ans.push_back(root);

//     }
// }
// }
// return ans;
// }

map<pair<int,int>,vector<TreeNode*>>dp;
vector<TreeNode*>allPossibleBST(int start,int end){
    if(start>end)return {0};
    if(start==end)return {new TreeNode(start)};
    if(dp.find({start,end})!=dp.end())return dp[{start,end}];
     vector<TreeNode*>ans;
    for(int i=start;i<=end;i++){
        vector<TreeNode*>left=allPossibleBST(start,i-1);
        vector<TreeNode*>right=allPossibleBST(i+1,end);
        for(int j=0;j<left.size();j++){
            for(int k=0;k<right.size();k++){
                TreeNode*root=new TreeNode(i);
                root->left=left[j];
                root->right=right[k];
                ans.push_back(root);
            }
        }
        
    }
    return dp[{start,end}]=ans;
}
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return {};
       
         return allPossibleBST(1, n);
    }
};