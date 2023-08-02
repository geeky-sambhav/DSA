class Solution {
public:
TreeNode* solve(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int poststart,int postend,unordered_map<int,int>&mapping){
if(poststart>postend || instart>inend){
    return NULL;
    }

TreeNode* root=new TreeNode(postorder[postend]);
int rootindex=mapping[root->val];
int leftnodes=rootindex-instart;
root->left=solve(inorder,instart,rootindex-1,postorder,poststart,poststart+leftnodes-1,mapping);
root->right=solve(inorder,rootindex+1,inend,postorder,poststart+leftnodes,postend-1,mapping);
return root;


}


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        unordered_map<int,int>mapping;
        for (int i=0;i<inorder.size();i++){
            mapping[inorder[i]]=i;
        }

        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mapping);
    }
};  