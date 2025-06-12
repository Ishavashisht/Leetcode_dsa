class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        while (curr) {
            if (!curr->left) {
                // Visit node
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Find the rightmost node in left subtree (Morris threading)
                TreeNode* pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;

                if (!pre->right) {
                    // Thread the tree
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    // Restore the tree
                    pre->right = nullptr;

                    // Visit node
                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        // Swap the values of the two misplaced nodes
        if (first && second)
            swap(first->val, second->val);
    }
};
