class Solution {
    int left(TreeNode* root){
        int height=0;
        if(root==NULL) return height;
        while(root){
            height++;
            root=root->left;
        }
    return height;
    }
   int right(TreeNode* root){
        int height=0;
        if(root==NULL) return height;
        while(root){
            height++;
            root=root->right;
        }
    return height;
    }


public:
    int countNodes(TreeNode* root) {
        int nodes=0;
        if(root==NULL) return nodes;
        int lh=left(root);
        int rh=right(root);
        if(lh==rh) return (1<<lh)-1; //2**lh
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};

// TC (LOGN)^2
// SC LOGN