INTUTION
SIMPLE INORDER LGA K CHK KRO KI EK BAAR GALAT HAI K 2 BAAR


class Solution {
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
public:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL && root->val<prev->val){
            //first time
            if(first==NULL){
                first=prev;
                middle=root;
            }
            //second time
            else{
                last=root;
            }


        }
        prev=root;
        inorder(root->right);


    }

    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
         if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);

    }
};


