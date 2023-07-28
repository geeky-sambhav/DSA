class Solution {
public:
int solve(TreeNode* root,int &maxi){

        if(root==NULL) return 0;
        
        int lh=max(0,solve(root->left,maxi));
        int rh=max(0,solve(root->right,maxi));
        maxi=max(maxi,root->val+lh+rh);
        return root->val+max(lh,rh);


}

    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;

    }
};