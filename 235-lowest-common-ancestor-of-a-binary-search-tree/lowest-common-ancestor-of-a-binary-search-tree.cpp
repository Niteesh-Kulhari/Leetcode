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
private:
    bool find(TreeNode* root, TreeNode*p, TreeNode* q, TreeNode*& ans){
        if(root == NULL){
            return false;
        }

        bool current = (root == p || root == q);

        bool left = find(root->left, p, q, ans);
        bool right = find(root->right, p, q, ans);

        if(current + left + right >= 2) ans = root;

        return left || right || current;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;

        find(root, p, q, ans);

        return ans;
    }
};