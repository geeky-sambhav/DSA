pair<int,int> solve(BinaryTreeNode<int>* root, int key){

int pred=-1;
int succ=-1;
BinaryTreeNode<int>* temp=root;
while(temp->data!=key){
    if(temp->data>key){
        succ=temp->data;
        temp=temp->left;
    }
    else      {
        pred = temp->data;
        temp = temp->right;
      }
}
BinaryTreeNode<int>* left=temp->left;
while(left!=NULL){
    pred=left->data;
    left=left->right;
}
BinaryTreeNode<int>* right=temp->right;
while(right!=NULL){
    succ=right->data;
    right=right->left;
}
return{pred,succ};
}




pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    return solve(root,key);
}
