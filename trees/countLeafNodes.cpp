int countLeaves(Node* root)
{
 int count=0;
    if (root==NULL){
        return 0;
    }
Node* curr=root;
 if(root->left==NULL && root->right==NULL){
     return 1;
 }
 int lnodes=countLeaves(curr->left);
int  rnodes=countLeaves(curr->right);
 return lnodes+rnodes;
}