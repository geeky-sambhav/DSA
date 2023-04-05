void inorder(TreeNode<int>* root, vector<int>&v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
TreeNode<int>* balance(int s,int e,vector<int>&v){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int>* node=new TreeNode<int>(v[mid]);
    node->left=balance(s,mid-1,v);
    node->right=balance(mid+1,e,v);
    return node;
    }
TreeNode<int>* balancedBst(TreeNode<int>* root) {
   vector<int>v;
  inorder(root,v);
 return balance(0,v.size()-1,v);

}