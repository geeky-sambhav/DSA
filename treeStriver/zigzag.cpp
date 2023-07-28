class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        int flag=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>level;
                for (int i =0;i<s;i++){
                    TreeNode* node=q.front();
                    q.pop();
                    level.push_back(node->val);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);


                }
                if(flag==0) {ans.push_back(level);
                flag=1;}
                else{
                    reverse(level.begin(),level.end());
                    ans.push_back(level);
                    flag=0;
                }
            }
             
        
        return ans;
    }
};


  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        bool flag=true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>level(s);
                for (int i =0;i<s;i++){
                    TreeNode* node=q.front();
                    q.pop();
                    int index=flag?i:s-i-1;
                    level[index]=node->val;
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);


                }
               ans.push_back(level);
                flag=!flag;}
               
            
             
        
        return ans;
    }
};


