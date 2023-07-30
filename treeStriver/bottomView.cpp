class Solution {
  public:
    vector <int> bottomView(Node *root) {
       vector<int>ans;
if(root==NULL) return ans;
map<int,int>mapping;
queue<pair<Node*,int>>q;
q.push({root,0});
while(!q.empty()){
    auto p=q.front();
    q.pop();
   Node* node=p.first;
    int x=p.second;
    mapping[x]=node->data;
    if(node->left) q.push({node->left,x-1});
    if(node->right) q.push({node->right,x+1});
}
for(auto i:mapping){
    ans.push_back(i.second);
}
return ans;
    }
};