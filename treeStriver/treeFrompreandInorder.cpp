class Solution {
    TreeNode* solve(vector<int>& preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend, unordered_map <int,int>&mapping){
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int rootindex=mapping[root->val];
        int leftnodes=rootindex-instart;
        root->left=solve(preorder,prestart+1,leftnodes+prestart,inorder,instart,rootindex-1,mapping);
  root->right=solve(preorder,leftnodes+prestart+1,preend,inorder,rootindex+1,inend,mapping);
return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int,int>mapping;
        for (int i=0;i<inorder.size();i++){
            mapping[inorder[i]]=i;
        }
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mapping);
    }
};