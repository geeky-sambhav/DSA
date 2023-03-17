// WE WILL MAKE A PAIR WHERE WE WILL STORE ROOT ELEMENT IS INCLUDED AND IN OTHER ROOT ELEMENT IS NOT INCLUDED
// FUNCTION MEIN EK PAIR BNA LENGE JISME  EXCLUDED VALUE HOGI AUR EK MEIN INCLUDED VALUE HOGI


// CAN BE SOLVED BETTER USING DP 
class Solution{

  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node *root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        pair<int,int>res;
        //including vali value
        res.first=root->data+left.second+right.second;
        //excluding vali value
        res.second=max(left.first,left.second)+max(right.first,right.second);
        return res;
        
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }
};