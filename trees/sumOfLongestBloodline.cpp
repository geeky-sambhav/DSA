class Solution
{
public:
    void solve(Node *root,int &maxsum,int sum,int len,int &maxlen){
        if (root==NULL){
            
            if(len>maxlen){
                maxlen=len;
                maxsum=sum;
            }
            else if(len==maxlen){
                maxsum=max(maxsum,sum);
            }
            return;
        }
        sum+=root->data;
        solve(root->left,maxsum,sum,len+1,maxlen);
       solve(root->right,maxsum,sum,len+1,maxlen);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
         int maxSum=INT_MIN;
         int sum=0;
         int len=0;
         int maxLen=INT_MIN;
         solve(root,maxSum,sum,len,maxLen);
         return maxSum;
    }
};