
class Solution{
    public:
     struct Info
    {
        int size;
        int ans;
        int min;
        int max;
        bool isBST;
    };
    
    Info LargestBST(Node* root)
    {
        if(!root)
         return {0, 0, INT_MAX, INT_MIN, true};
         
        if(root->left == NULL and root->right == NULL)
         return {1, 1, root->data, root->data, true};
         
        Info L = LargestBST(root->left);
        Info R = LargestBST(root->right);
        
        Info curr;
        curr.size = (1 + L.size + R.size);
        
        if(L.isBST and R.isBST and L.max < root->data and R.min > root->data)
        {
            curr.min = min(L.min, root->data);
            curr.max = max(R.max, root->data);
            curr.ans = (1 + L.ans + R.ans);
            curr.isBST = true;
            
            return curr;
        }
        
        curr.ans = max(L.ans, R.ans);
        curr.isBST = false;
        
        return curr;
    }
    int largestBst(Node *root)
    {
        //Your code here
        
        Info curr = LargestBST(root);
        
        return curr.ans;
        
    }
};