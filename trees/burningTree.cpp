// HAR NODE KA PARENT FIND KRO
// FIND THE TARGET NODE JO NODE KA PARENT FIND KRNE VALE FUNCTION SE HI MIL JAYEGI
// BURN KRDO:
// AGR LEFT HAI/RIGHT/PARENT HAI TO VISITED TRUE KRDO
// EK FLAG LENGE KI AGR KUCH BHI CHNAGE HUA TO FLAG =1
// NICHE CHECK KREGE AGR FLAG CHANGE HUA MEANS KUCH BURN HUA TO ANS++ KR DENGE

class Solution {
  public:
  Node* ntp(Node* root, int target,map<Node*,Node*>&nodetoparent){
      if(root==NULL){
          return NULL;
      }
      queue<Node*>q;
      Node* res=NULL;
      q.push(root);
      nodetoparent[root]=NULL;
      while(!q.empty()){
          Node* front=q.front();
          q.pop();
          if(front->data==target){
              res=front;
          }
          if(front->left){
              nodetoparent[front->left]=front;
              q.push(front->left);
          }
           if(front->right){
              nodetoparent[front->right]=front;
              q.push(front->right);
          }
        
      }
      return res;
  }
  int burntree(Node* root,Node* target,map<Node*,Node*>&nodetoparent){
      
      queue<Node*>q;
      q.push(target);
      int ans=0;
      map<Node*,bool>visited;
      visited[target]=1;
      while(!q.empty()){
      int flag=0;
         int size=q.size();
         for (int i=0;i<size;i++){// process the neighbouring nodes
             Node* front=q.front();
             q.pop();
             if(front->left && !visited[front->left]){
                 q.push(front->left);
                 visited[front->left]=1;
                 flag=1;
             }
              if(front->right && !visited[front->right]){
                 q.push(front->right);
                 visited[front->right]=1;
                 flag=1;
             }
             if(nodetoparent[front] && !visited[nodetoparent[front]]){
                 q.push(nodetoparent[front]);
                 visited[nodetoparent[front]]=1;
                 flag=1;
             }
         }
         if(flag==1){ans++;
      }
  }
      return ans;
      
  }
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>nodetoparent;
        Node* targett=ntp(root,target,nodetoparent);
        return burntree(root,targett,nodetoparent);
    }
};