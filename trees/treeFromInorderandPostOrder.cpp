// ISME HM PEHLE RIGHT SUBTREE BNAYEGE COZ ROOT LIES IN THE RIGHT PART

class Solution {
public:
unordered_map<int,int>m;
TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int instart,int inend,int &poststart,int postend){
    if(instart>inend || poststart<postend){
        return NULL;
    }
    int element=postorder[poststart--];
    int position=m[element];
    TreeNode* root=new TreeNode(element);
    root->right=solve(inorder,postorder,position+1,inend,poststart,postend);
    root->left=solve(inorder,postorder,instart,position-1,poststart,postend);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        int instart=0;
        int poststart=n-1;
        return solve(inorder,postorder,instart,n-1,poststart,0);
    }
};