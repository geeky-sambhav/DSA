class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
      queue<Node *> q;
        q.push(root);

        // Used to store the level
    unordered_set<int> a;

        int level = 0;
        while(!q.empty()){
            int size=q.size();
            for (int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                if(front->left==NULL && front->right==NULL){
                    a.insert(level);
                }
                if(front->left){
                    q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        level++;
        if(a.size()>1){
            return false;
        }
    }
    return true;
    }
};