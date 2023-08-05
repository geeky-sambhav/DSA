class bstIterator{
    stack<TreeNode*>st;
    bool reverse=true;
public:
bstIterator(TreeNode* root,bool isReverse){
reverse=isReverse;
pushall(root);
}
int next(){
    TreeNode* temp=st.top();
    st.pop();
    if(!reverse){
        pushall(temp->right);
    }
    else{
        pushall(temp->left);
    }
    return temp->val;
}
bool hasnext(){
    return (!st.empty());
}

void pushall(TreeNode* root){
    while(root){
        st.push(root);
        if(reverse){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
}



};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        bstIterator l(root,false);
        bstIterator r(root,true);

        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j>k) j=r.next();
            else{
                i=l.next();
            }
        }
        return false;
    }
};