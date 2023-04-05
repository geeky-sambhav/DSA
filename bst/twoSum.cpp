void inorder(BinaryTreeNode<int>* root,vector<int>&v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int>v;
    inorder(root,v);
    int i=0;
    int j=v.size()-1;
    while(i<j){
    int sum=v[i]+v[j];
        if(sum>target){
            j--;
        }
        else if(sum<target)
        i++;
        else{
            return true;
        }
    }
    return false;
}