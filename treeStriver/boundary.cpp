class Solution {
    bool isLeaf(Node* root){
        if (root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    
    void leftTraversal(Node *root,vector<int>&ans){
        
        Node* curr=root->left;
        while(curr){
           if(!isLeaf(curr)) ans.push_back(curr->data);
           if(curr->left) {curr=curr->left;}
            else{
                curr=curr->right;
        }
        
    }
    }
    
    void leafTraversal(Node*root,vector<int>&ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
           return;
            
        }
        if(root->left) leafTraversal(root->left,ans);
        if(root->right) leafTraversal(root->right,ans);
        }
    
    void rightTraversal(Node *root,vector<int>&ans){
      
        Node* curr= root->right;
        vector<int>temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right){curr=curr->right;}
            else{
             curr=curr->left;
                }
            
        } 
     for (int i=temp.size()-1;i>=0;i--){
         ans.push_back(temp[i]);
     }   
    }
        
        public:





    vector <int> boundary(Node *root)
    {
       vector<int>ans;
       if(root==NULL) return ans;
       if(!isLeaf(root)) ans.push_back(root->data);
       leftTraversal(root,ans);
       leafTraversal(root,ans);
       rightTraversal(root,ans);
       
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}