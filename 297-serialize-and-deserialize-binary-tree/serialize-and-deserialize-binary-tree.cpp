/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        deque<TreeNode*> dq;
        if(!root) return "";
        dq.push_back(root);
        while(dq.size()>0){
            int n=dq.size();
            for(int e=0;e<n;e++){
                TreeNode* treeNode=dq.front();
                dq.pop_front();
                int num=(treeNode==NULL)?1001:treeNode->val;
                if(num!=1001){
                    if(treeNode->left){
                        dq.push_back(treeNode->left);
                    }else{
                        dq.push_back(NULL);
                    }
                    if(treeNode->right){
                        dq.push_back(treeNode->right);
                    }else{
                        dq.push_back(NULL);
                    }
                }
                str+=to_string(num);
                str+=",";
            }
        }
        str=str.substr(0,str.size()-1);
        // cout<<str<<endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        int e = 0;
        int n = data.size();
        queue<int> q;
        queue<TreeNode*> q2;

        while(e < n){
            string temp = "";
            while(e<n && data[e]!=','){
                temp += data[e];
                e++;
            }
            q.push(stoi(temp));
            e++;
        }
        TreeNode* root = new TreeNode(q.front());
        q.pop();
        q2.push(root);

        while(!q.empty()){
            TreeNode* temp = q2.front();
            q2.pop();
            if(!q.empty()){
                int left = q.front();
                q.pop();
                if(left != 1001){
                    temp->left = new TreeNode(left);
                    q2.push(temp->left);
                }
            }
            if(!q.empty()){
                int right = q.front();
                q.pop();
                if(right != 1001){
                    temp->right = new TreeNode(right);
                    q2.push(temp->right);
                }
            }
        }

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));