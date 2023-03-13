class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node==NULL){
            return 0;
        }
        int leftheight=height(node->left);
        int rightheight=height(node->right);
        return max(leftheight,rightheight)+1;
    }
};