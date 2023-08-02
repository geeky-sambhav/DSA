class Solution {
public:
void parenttonode(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mapping){

queue<TreeNode*>q;
q.push(root);
while(!q.empty()){
TreeNode* node=q.front();
q.pop();
if(node->left){
    mapping[node->left]=node;
    q.push(node->left);
}
if(node->right){
    mapping[node->right]=node;
    q.push(node->right);
}}}


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>mapping;
        parenttonode(root,mapping);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        q.push(target);
        vis[target]=true;
        int len=0;
        while(!q.empty()){
            if(len==k) break;
            len++;
            int size=q.size();
            for (int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
            if(node->left && !vis[node->left]) {q.push(node->left);
            vis[node->left]=true;}
            if(node->right && !vis[node->right]){
            q.push(node->right);
            vis[node->right]=true;    
            }
            if(mapping[node] && !vis[mapping[node]]){
                q.push(mapping[node]);
                vis[mapping[node]]=true;
            }


            }
        }
       while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
return ans;
    }
};