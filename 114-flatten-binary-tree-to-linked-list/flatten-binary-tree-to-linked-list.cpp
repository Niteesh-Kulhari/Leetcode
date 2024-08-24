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
    void flatten(TreeNode* root) {
        if (root == NULL) return;

        vector<TreeNode*> preorder;
        findPreorder(root, preorder);

        int n = preorder.size();
        for (int i = 0; i < n - 1; i++) {
            TreeNode* node = preorder[i];
            node->left = NULL;
            node->right = preorder[i + 1];
        }

        preorder[n - 1]->left = NULL;
        preorder[n - 1]->right = NULL;
    }

private:
    void findPreorder(TreeNode* root, vector<TreeNode*>& preorder) {
        if (root == NULL) return;

        preorder.push_back(root);
        findPreorder(root->left, preorder);
        findPreorder(root->right, preorder);
    }
};
