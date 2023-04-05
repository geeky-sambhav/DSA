BinaryTreeNode<int>* solve(vector<int> &v,int max,int min,int &i)
{
    if(i>=v.size() ){
        return NULL;
    }
if(v[i]>max || v[i]<min){
    return NULL;
}
BinaryTreeNode<int>* node=new BinaryTreeNode<int>(v[i++]);
node->left=solve(v,node->data,min,i);
node->right=solve(v,max,node->data,i);
return node;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int max=INT_MAX;
    int min=INT_MIN;
    int i=0;
        return solve(preorder,max,min,i);
}