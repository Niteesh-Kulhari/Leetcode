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
    bool isValidBST(TreeNode* root) {
        bool ans = valid(root, LONG_MIN, LONG_MAX);

        return ans;
    }

private: 
    bool valid(TreeNode* root, long lr, long ur){
        if(root == NULL){
            return true;
        }

        if(root->val <= lr || root->val >= ur){
            return false;
        }

        bool left = valid(root->left, lr, root->val);
        bool right = valid(root->right, root->val, ur);

        return left && right;
    }
};