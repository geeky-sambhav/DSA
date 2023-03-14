
class Solution{
    public:
    int height(Node* root){
        if(root==NULL){
            return 0;
        }
        
        int lh=height(root->left);
        if(lh==-1){
            return -1; //immediately return -1
        }
        int rh=height(root->right);
        if(rh==-1){
            return -1;
        }
        if (abs(lh-rh)>1){
            return -1;
        }
        return 1+max(lh,rh);
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(height(root)!=-1)
        return 
            true;
        
        else{
            return false;
        }
    }
};
