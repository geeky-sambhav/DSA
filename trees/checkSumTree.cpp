class Solution
{
    public:
    int solve(Node* root,int &ans){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){    //child node
            return root->data;
        }
        if(ans==0){
            return 0;
        }
        int lt=solve(root->left,ans);
        int rt=solve(root->right,ans);
        if(lt+rt!=root->data){
            return ans=0;
        }   
        return (lt+rt+root->data) ;
    }
    bool isSumTree(Node* root)
    {
        int ans=1;
        int a=solve(root,ans);
        if(ans!=1){
            return false;
        }
        else{
            return true;
        }
    }
};