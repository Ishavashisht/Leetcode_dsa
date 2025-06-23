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
   unordered_map<int, vector<TreeNode*>> memo;

vector<TreeNode*> allPossibleFBT(int n) {

    if (n % 2 == 0) return {}; // FBTs require an odd number of nodes.
    if (n == 1) return {new TreeNode(0)}; // Base case: single node tree.
    
    if (memo.count(n)) return memo[n]; // Return cached result if available.

    vector<TreeNode*> res;
    for (int leftNodes = 1; leftNodes < n; leftNodes += 2) { // Iterate over odd counts
        int rightNodes = n - 1 - leftNodes; // Remaining nodes for the right subtree.

        vector<TreeNode*> leftSubTrees = allPossibleFBT(leftNodes); 
        vector<TreeNode*> rightSubTrees = allPossibleFBT(rightNodes);

        for (TreeNode* left : leftSubTrees) {
            for (TreeNode* right : rightSubTrees) {
                TreeNode* root = new TreeNode(0);
                root->left = left;
                root->right = right;
                res.push_back(root);
            }
        }
    }

    memo[n] = res; // Cache the result.
    return res;
}
};