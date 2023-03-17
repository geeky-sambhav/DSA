// PRE KA PEHLA ELEMENT IS ROOT SO USKI POSITION NIKALO INORDER MEIN
// FIR ROOT ELEMENT CREATE KRLO
// FIR ROOT KA LEFT AND RIGHT ELEMENT CREATE KRO

class Solution {
public:
unordered_map<int,int>m;
 TreeNode* solve(vector<int> in,vector<int> &pre,int &preindex,int inindex,int inend,int preend){
     if(preindex>preend || inindex>inend){
         return NULL;
     }
     int element=pre[preindex++];
     TreeNode* root=new TreeNode(element);
     int position=m[element];
     root->left=solve(in,pre,preindex,inindex,position-1,preend);
     root->right=solve(in,pre,preindex,position+1,inend,preend);
     return root;
 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
         int preorderindex=0;
        int inorderindex=0;
        for (int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        TreeNode* ans=solve(inorder,preorder,preorderindex,0,n-1,n-1);
        return ans;
    }
};