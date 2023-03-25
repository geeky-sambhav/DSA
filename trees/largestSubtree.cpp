class Solution {
  public:
    // Function to find largest subtree sum.
    int solve(Node* root,int &sum){
        if(root==NULL){
            return 0;
        }
        int l=solve(root->left,sum);
        int r=solve(root->right,sum);
        sum=max(sum,l+r+root->data);
        return l+r+root->data;
        
        
    }
    int findLargestSubtreeSum(Node* root)
    {
        if(root==NULL){
            return 0;
        }
        int sum=INT_MIN;
       solve(root,sum);
        return sum;
        
    }
};
