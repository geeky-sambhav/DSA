// INTUTION
// INSERT AT THE LEAF 
// FOR THIS TRAVERSE TILL THE LAST


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) { TreeNode* node=new TreeNode(val);
        return node;}
        TreeNode* curr=root;
        while(curr){
            if(curr->val>=val){
                if(curr->left!=NULL) curr=curr->left;
                else{
                    curr->left=new TreeNode(val);
                    break;
                }

            }
        else{
            if(curr->right!=NULL) curr=curr->right;
                else{
                    curr->right=new TreeNode(val);
                    break;
                }



        }
        }
        return root;
    }
};