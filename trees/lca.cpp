// JAHA PE N1 YA N2 MILTA VO NODE RETURN KRDO
// LEFT MEIN CALL MARO AUR RIGHT MEIN CALL MAARO
// AGR LEFT SE KUCH AAYA MEANS VO NOT NULL HAI TO LEFT RETURN KRDO AND VICE VERSA



class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL){
            return NULL;
        }
        if(root->data==n1 || root->data==n2){
            return root;
        }
        Node* left=lca(root->left,n1,n2);
        Node* right=lca(root->right,n1,n2);
        if(left!=NULL && right!=NULL){
            return root;
        }
        else if(left!=NULL && right==NULL){
            return left;
        }
        else if(left==NULL && right!=NULL){
            return right;
        }
        else{
            return NULL;
        }
        
    }
};