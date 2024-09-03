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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrder;
        findInorder(root, inOrder);
        int num;
        for(int i=0; i<k; i++){
            if(i == k-1) num = inOrder[i]; 
        }

        return num;
    }

private:
    void findInorder(TreeNode* root, vector<int>& inOrder){
        if(root==NULL) return;

        findInorder(root->left, inOrder);
        inOrder.push_back(root->val);
        findInorder(root->right, inOrder);
    }
};