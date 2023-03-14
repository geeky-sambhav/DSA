class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int solve(Node *root, int &d){
        if(root==NULL){
            return 0;
        }
        int lh=solve(root->left,d);
        int rh=solve(root->right,d);
        d=max(d,lh+rh+1);
        return 1+max(lh,rh);
        
    }
    int diameter(Node* root) {
      int d=0;
      int a= solve(root,d);
      return d;
    }
};