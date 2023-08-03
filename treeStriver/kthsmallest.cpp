class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans;
        TreeNode* curr = root;
        
        while(curr){
            if(curr->left == NULL){
                count++;
                if(count == k){
                    ans = curr->val;
                }
                
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    count++;
                    prev->right = NULL;
                    if(count == k){
                        ans = curr->val;
                    }
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};