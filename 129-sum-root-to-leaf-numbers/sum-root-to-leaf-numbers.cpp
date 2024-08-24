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
    int sumNumbers(TreeNode* root) {

        if(root == NULL){
            return 0;
        }
        int sum = 0;

        findSum(root, sum, 0);

        return sum;
    }

private:
    void findSum(TreeNode* root, int& totalSum, int currVal){
        if(root == NULL){
            return;
        }

        currVal = root->val + currVal * 10;
        
        

        if(root->left == NULL & root->right == NULL){
            totalSum += currVal;
        }

        findSum(root->left, totalSum, currVal);
        findSum(root->right, totalSum, currVal);
    }
};