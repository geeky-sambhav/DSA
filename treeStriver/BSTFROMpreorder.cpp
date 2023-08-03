class Solution {
TreeNode* solve(vector<int>&preorder,int &i,long max){
if(i==preorder.size() || preorder[i]>max){
    return NULL;
}
TreeNode* node=new TreeNode(preorder[i++]);
node->left=solve(preorder,i,node->val);
node->right=solve(preorder,i,max);
return node;



}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,LONG_MAX);
    }
};