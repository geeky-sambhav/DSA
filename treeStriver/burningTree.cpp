class Solution {
    Node* parentToNode(map<Node*,Node*>&mapping,Node* root,int target){
   
        
queue<Node*>q;
q.push(root);
Node* tar=root;
while(!q.empty()){
Node* node=q.front();
if(node->data==target){
     tar=node;
}
q.pop();
if(node->left){
    mapping[node->left]=node;
    q.push(node->left);
}
if(node->right){
    mapping[node->right]=node;
    q.push(node->right);
    }
}  
return tar;
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        int time=0;
      map<Node*,Node*>mapping;
      Node* tar=parentToNode(mapping,root,target);
      map<Node*,bool>vis;
      queue<Node*>q;
      q.push(tar);
      vis[tar]=true;
      while(!q.empty()){
          int f=0;
          int size=q.size();
          for(int i=0;i<size;i++){
              Node* node=q.front();
              q.pop();
              if(node->left && !vis[node->left]) {
            q.push(node->left);
            vis[node->left]=true;
            f=1;
                  }
                  
             if(node->right && !vis[node->right]) {
            q.push(node->right);
            vis[node->right]=true;
            f=1;
                  }
                  
                  
            if(mapping[node] && !vis[mapping[node]]){
                q.push(mapping[node]);
                vis[mapping[node]]=true;
                f=1;
            }
          }
          if(f==1){
              time++;
          }
      }
      return time;    
    }
};
