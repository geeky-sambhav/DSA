class Solution {
public:
    void flatten(TreeNode* root) {
         
         TreeNode* curr=root;
         while(curr){
                if(curr->left){
                    TreeNode* leftnode=curr->left;
                    while(leftnode->right){
                        leftnode=leftnode->right;
                        }
                        leftnode->right=curr->right;
                        curr->right=curr->left;
                        curr->left=NULL;

                        }
                        curr=curr->right;



         }
    }
};