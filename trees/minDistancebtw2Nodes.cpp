class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lcaa(Node* root,int a ,int b){
        if(root==NULL){
            return NULL;
        }
        if(root->data==a || root->data==b){
            return root;
        }
        Node* l=lcaa(root->left,a,b);
        Node* r=lcaa(root->right,a,b);
        if(l!=NULL && r!=NULL){
            return root;
        }
        else if (l==NULL && r!=NULL){
            return r;
        }
        else if (l!=NULL && r==NULL){
            return l;
        } 
        else{
            return NULL;
        }
    }
    int distance(Node* root,int a){
        int d=0;
        if(root==NULL){
            return -1;
        }
        if(root->data==a){
            return 0;
        }
        int l=distance(root->left,a);
        int r=distance(root->right,a);
        if(l==-1 && r==-1){
            return -1;
        }
        else if (l==-1 ){
            return r+1;
        }
        else if (r==-1){
            return l+1;
        }
    }
    int findDist(Node* root, int a, int b) {
        Node* lca=lcaa(root,a,b);
        int d1=distance(lca,a);
        int d2=distance(lca,b);
        return d1+d2;
    }
};