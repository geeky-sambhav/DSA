class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
      
        TreeNode* curr=root;
   
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL) {
                    prev->right=curr;
                    // ans.push_back(root->val) for preorder
                    curr=curr->left;
                     }
                else{
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
                
            }



        }
        return ans;
    }
};