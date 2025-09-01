/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    void addParent(TreeNode*root){
        if(!root)return;
        if(root->left)parent[root->left]=root;
        addParent(root->left);
        if(root->right)parent[root->right]=root;
        addParent(root->right);

    }
    void collectKDist(TreeNode*target,int k,vector<int>&res){
        queue<TreeNode*>que;
        que.push(target);
        unordered_set<int> vis;
        vis.insert(target->val);
         while(!que.empty()) {
            
            int n = que.size();
            if(k == 0)
                break;
            
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                
                if(curr->left && !vis.count(curr->left->val)) {
                    que.push(curr->left);
                    vis.insert(curr->left->val);
                }
                if(curr->right && !vis.count(curr->right->val)) {
                    que.push(curr->right);
                    vis.insert(curr->right->val);
                }
                
                if(parent.count(curr) && !vis.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    vis.insert(parent[curr]->val);
                }
            }
            k--;
        }
        
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            res.push_back(temp->val);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        addParent(root);
        collectKDist(target,k,res);
        return res;
    }
};