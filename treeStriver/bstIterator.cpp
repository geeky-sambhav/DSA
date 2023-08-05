class BSTIterator {
    stack<TreeNode*>st;
public:

    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        if(temp->right) pushall(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
    void pushall(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
};

NODE AND SARE LEFT VALE STACK MEIN PUSH KRTE JAO 
JB KHTM HO JAYE TO POP KRO AUR RIGHT MEIN BHI SAME KAAM KRO IE PUSH THE NODE AND THE LEFT ELEMENTS

IF WE WANT THE BEFORE ELEMENTS JUST DO  THE OPPOSITE IE PUSH THE RIGHT ELEMETS IN THE STACK AND THEN THE LEFT