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
    void find(TreeNode* root, int& count, int currMax){
        if(root == NULL) return;
        if(root->val >= currMax){
            count++;
            currMax = root->val;
        }

        if(root->left) find(root->left, count, currMax);
        if(root->right) find(root->right, count, currMax);

    }
public:
    int goodNodes(TreeNode* root) {
        
        if(root == NULL) return 0;
        int count = 0;
        find(root, count, root->val);
        return count;
    }
};