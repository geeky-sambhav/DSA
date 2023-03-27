class Solution {
public:
    TreeNode* maxi(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        while(root->right){
            root=root->right;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){

            //0 CHILD
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //1 CHILD
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            //2 CHILDREN
            if(root->left!=NULL && root->right!=NULL){
                TreeNode* maxLeft=maxi(root->left);
                root->val=maxLeft->val;
                root->left=deleteNode(root->left,maxLeft->val);
                return root;
            }
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
            return root;
        }
        else{
            root->left=deleteNode(root->left,key);
            return root;
        }
        return root;
    }
};