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
private:
    void inOrder(TreeNode* root, int& count, int& ans, int& k){
        if(root == NULL) return;

        inOrder(root->left, count, ans, k);
        count++;
        if(count == k) ans = root->val;
        inOrder(root->right, count, ans, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        int count = 0;
        int ans = 0;
        inOrder(root, count, ans, k);

        return ans;
    }
};