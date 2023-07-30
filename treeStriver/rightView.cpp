class Solution {
public:
void solve(TreeNode* root,vector<int>&ds,int level){
if(root==NULL) return;

if(ds.size()==level) ds.push_back(root->val);
solve(root->right,ds,level+1);
solve(root->left,ds,level+1);
}

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ds;
        solve(root,ds,0);
        return ds;
    }
};


//ITERATIVE

 vector<int> rightSideView(TreeNode* root) {
        vector<int>ds;
        if(root==NULL) return ds;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            ds.push_back(node->val);
            int s=q.size();
            for (int i=0;i<s;i++){
                     TreeNode* curr=q.front();
                    q.pop();
                    if(curr->right) q.push(curr->right);
                    if(curr->left) q.push(curr->left);
            }
           
        }
        return ds;
    }