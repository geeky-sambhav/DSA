class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if(root==NULL) return 0;
        // int left=maxDepth(root->left);
        // int right=maxDepth(root->right);
        // return 1+max(left,right);

        queue<TreeNode*>q;
        int depth=0;
        if(root==NULL) return depth;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            depth++;
            for (int i=0;i<s;i++){
                    TreeNode* node=q.front();
                    q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);

            }

        }

return depth;



    }
};