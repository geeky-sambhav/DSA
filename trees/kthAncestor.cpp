// NODE TK JAATE JAO JB NODE MIL JAYE TO K KO DECREMENT KRTE JAO JBTK VO 0 NA HO JAYE
// AGR ROOT MEIN HI MIL AYE TO -1 KRDO

Node* solve(Node *root, int &k, int node ){
    if(root==NULL){
        return NULL;
    }
       if(root->data == node) 
    {
        return root;
    }
    Node* left=solve(root->left,k,node);
    Node* right=solve(root->right,k,node);
    if(left!=NULL && right==NULL){
        k--;
        if(k==0){
            
            return root;
        }
        return left;
    }
     if(left==NULL && right!=NULL){
      k--;
        if(k==0){
            
            return root;
        }
        return right;
        
    }
    return NULL;
    }

int kthAncestor(Node *root, int k, int node)
{
    Node* ans=solve(root,k,node);
    if(root==NULL || ans->data==node){
        return -1;
    }
    else{
        return ans->data;
    }
    
}
