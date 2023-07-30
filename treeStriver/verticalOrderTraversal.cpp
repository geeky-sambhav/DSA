class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mapping;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int x=p.second.first;
            int y=p.second.second;
            mapping[x][y].insert(node->val);
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});


        }
        vector<vector<int>>ans;
        for (auto i:mapping){
            vector<int>col;
            for (auto j:i.second){
            col.insert(col.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};