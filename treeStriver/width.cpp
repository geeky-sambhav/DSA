//MAKE INDEXES SUCH THAT AT EACH LEVEL IT STARTS FROM 0 TO PREVENT OVERFLOW IN SKEW TREE
TO MAKE THIS HAPPEN AT LEVEL THE INDEX OF EVERY NODE SHOULD BE INDEX OF THAT NODE- MINIMUM INDEX


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            int min=q.front().second;
            int first,last;
            for (int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                int ind=node.second-min;
    if(i==0) first=ind;
    if(i==s-1) last=ind;
    
    if(node.first->left) q.push({node.first->left,(long long)2*ind+1});
    if(node.first->right) q.push({node.first->right,(long long)2*ind+2});
            }
    ans=max(ans,last-first+1);


        }
        return ans;
    }
};