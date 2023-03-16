// HAR LEVEL KI SBSE PEHLE VALI NODE PRINT KRDO
void solve(Node *root,int lvl,vector<int> &ans){
    if(root==NULL){
        return;
    }
    //THIS MEANS U HAVE REACHED A NEW LEVEL
    if(lvl==ans.size()){
ans.push_back(root->data);
    }
    solve(root->left,lvl+1,ans);
    solve(root->right,lvl+1,ans);
}
vector<int> leftView(Node *root)
{
   vector<int>ans;
   
   solve(root,0,ans);
   return ans;
}