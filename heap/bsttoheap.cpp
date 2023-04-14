
void inorder(BinaryTreeNode* root,vector<int>&v){
	if(root==NULL){
		return ;
	}
	inorder(root->left,v);
	v.push_back(root->data);
	inorder(root->right,v);
}
void bsttoheap(BinaryTreeNode* root,vector<int>v,int &i){
	if(root==NULL){
		return;
	}
	root->data=v[i++];
	bsttoheap(root->left,v,i);
	bsttoheap(root->right,v,i);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int>v;
	inorder(root,v);
	int i=0;

	bsttoheap(root,v,i);
	return root;
} 