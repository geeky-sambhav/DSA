// 2 LINKED LISTS KO MERGE KRLO BAKI RECURSION KR LEGA

Node* merge(Node* left,Node* right){
    if(left==NULL){
        return right;
    }
     if(right==NULL){
        return left;
    }
    Node* temp=new Node(0);
    Node* res=temp;
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->bottom=left;
            temp=left;
            left=left->bottom;
        }
        else{
            temp->bottom=right;
            temp=right;
            right=right->bottom;
        }
    }
    if(left!=NULL){
        temp->bottom=left;
    }
    else{
        temp->bottom=right;
    }
    return res->bottom;
}    
Node *flatten(Node *root)
{if (root==NULL || root->next==NULL){
    return root;
}
   root->next=flatten(root->next);
   root=merge(root,root->next);
   return root;
}