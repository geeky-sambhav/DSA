class Solution {
  public:
  bool cbt(struct Node* tree,int i,int n){
      if(tree==NULL){
          return true;
      }
      if(i>=n){
          return false;
      }
      else{
      bool left=cbt(tree->left,(2*i)+1,n);
      bool right=cbt(tree->right,(2*i)+2,n);
      return left && right;}
      
      
  }
  bool maxorder(struct Node* tree){
      //leaf node
      if(tree->left==NULL && tree->right==NULL){
          return true;
      }
      
      //single child
      if(tree->right==NULL){
        return(tree->data>tree->left->data);
      }
      
      else{
          bool left=maxorder(tree->left);
          bool right=maxorder(tree->right);
          
          return (left && right &&  tree->left->data<tree->data 
          && tree->right->data<tree->data);
          
          
      }
        
  }
  int totalnodes(struct Node* tree){
      if (tree==NULL){
          return 0;
      }
      return(1+totalnodes(tree->left)+totalnodes(tree->right));
      
  }
    bool isHeap(struct Node* tree) {
        int i=0;
        int nodes=totalnodes(tree);
        if(cbt(tree,i,nodes) && maxorder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};