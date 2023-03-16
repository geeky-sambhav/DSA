// AGR NODE KA LEFT HAI TO USKO QUEUE MEIN STORE KRLO
// NHI TO NODE KE RIGHT KO PRINT KRTE JAO

vector<int> diagonal(Node *root)
{
   vector<int>ans;
   if(root==NULL){
       return ans;
   }
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       Node* temp=q.front();
       q.pop();
       while(temp){
           ans.push_back(temp->data);
           if(temp->left){
           q.push(temp->left);}
           temp=temp->right;
       }
       
   }
   return ans;
}