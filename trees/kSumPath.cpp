// APPROACH:
// SARE PATHS FIND KRLO FIR UNME CHK KRO KI SUM K KE EQUAL AA RHA HAI K NHI

// VECTOR MEIN PUSH KRTE JAO LEFT AUR RIGHT KA DATA
// FIR PICHE SE DEKHO KI UNKA SUM K KE EQUAL AA RHA HAI KE NHI AUR COUNT BDHATE JAO
// VAPIS AATE TIME POP BHI KRTE JAO LAST ELEMENT KO

class Solution{
  public:
  void solve(Node *root,int k,vector<int> ans,int &count){
      if(root==NULL){
          return;
      }
     ans.push_back(root->data);
     solve(root->left,k,ans,count);
     solve(root->right,k,ans,count);
     int size=ans.size();
     int sum=0;
     for(int i=size-1;i>=0;i--){
         sum+=ans[i];
         if(sum==k){
             count++;
         }
     }
     ans.pop_back();
      
  }
    int sumK(Node *root,int k)
    {
      vector<int>ans;
      int count=0;
      solve(root,k,ans,count);
      return count;
    }
};