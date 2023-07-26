class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end());
        vector<int>dp(n,1);
int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
            if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1] && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;



                    }


            }
            if(dp[i]>maxi) maxi=dp[i];
        }
        return maxi;
    }
};


//BINARY SEARCH
class Solution {
public:
static bool cond(vector<int>&a,vector<int>&b){
if(a[0]==b[0]) return a[1]>b[1];
return a[0]<b[0];

}

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cond);
        vector<int>temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(envelopes[i][1]>temp.back()){
                temp.push_back(envelopes[i][1]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),
                envelopes[i][1])-temp.begin();
                temp[ind]=envelopes[i][1];
            }
        }
return temp.size();

    }
};