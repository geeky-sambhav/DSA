class Solution
{
    public: 
    void solve(Node* root, Node* &head,Node* &prev){
         if(root==NULL){
           return ;
       }
       solve(root->left,head,prev);
       if(prev==NULL){
           head=root;
       }
       else{
           root->left=prev;
           prev->right=root;
       }
       prev=root;
       solve(root->right,head,prev);
        
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        
       Node* prev=NULL;
        Node* head=NULL;
     solve(root,head,prev);
     return head;
    }
    
};