// SAME AS LEFT BUT PEHLE RIGHT SE VIEW KREGE

class Solution
{
    public:
    void solve(Node *root,int lvl,vector<int> &ans){
    if(root==NULL){
        return;
    }
    //THIS MEANS U HAVE REACHED A NEW LEVEL
    if(lvl==ans.size()){
ans.push_back(root->data);
    }
    //PEHLE RIGHT TREE BUILD HOGA
    solve(root->right,lvl+1,ans);
    solve(root->left,lvl+1,ans);
}
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {vector<int>ans;
   
   solve(root,0,ans);
   return ans;
       // Your Code here
    }
};
