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
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
        //inorderTraversal(root);
        //current = 0;
    }
    
    int next() {
        // return inorder[current++]->val;
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        // return current < inorder.size();
        return !myStack.empty();
    }

private:
    vector<TreeNode*> inorder;
    int current;
    
    void pushAll(TreeNode* root){
        if(root == NULL){
            return;
        }
        myStack.push(root);
        pushAll(root->left);
    }

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