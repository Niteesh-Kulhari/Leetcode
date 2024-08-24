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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
        current = 0;
    }
    
    int next() {
        return inorder[current++]->val;
    }
    
    bool hasNext() {
        return current < inorder.size();
    }

private:
    vector<TreeNode*> inorder;
    int current;

    void inorderTraversal(TreeNode* root){
        if(root== NULL){
            return;
        }

        inorderTraversal(root->left);
        inorder.push_back(root);
        inorderTraversal(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */