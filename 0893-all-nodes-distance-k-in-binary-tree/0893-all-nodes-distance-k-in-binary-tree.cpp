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
    unordered_map<TreeNode*, TreeNode*> parent;


    void inorder(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            parent[root->left] = root;
            inorder(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            inorder(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if (!root) return res;

        inorder(root); 

        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;

        q.push(target);
        vis.insert(target);

        while (!q.empty() && k > 0) {
            int n = q.size();
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                
                if (curr->left && !vis.count(curr->left)) {
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
              
                if (curr->right && !vis.count(curr->right)) {
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
              
                if (parent.count(curr) && !vis.count(parent[curr])) {
                    q.push(parent[curr]);
                    vis.insert(parent[curr]);
                }
            }
            k--; 
        }

      
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};
