class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL) ans.append("#,");
            else ans.append(to_string(node->val)+',');
            if(node) q.push(node->left);
            if(node) q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        string str;
        stringstream s(data);
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            //check for left
            getline(s,str,',');
            if(str=="#") node->left=NULL;
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                node->left=leftnode;
                q.push(leftnode);

            }
            //check for right
            getline(s,str,',');
            if(str=="#") node->right=NULL;
            else{
                TreeNode* rightnode=new TreeNode(stoi(str));
                node->right=rightnode;
                q.push(rightnode);

            }


        }
        return root;
    }
};
 