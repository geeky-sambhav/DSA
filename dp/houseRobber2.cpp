class Solution {
public:
int solve(vector<int >&arr){
int prev=arr[0];
int prev2=0;
for (int i=1;i<arr.size();i++){
int take=arr[i];
if(i>1) take+=prev2;
int nottake=0+prev;
int curr=max(take,nottake);
prev2=prev;
prev=curr;


}
return prev;



}

    int rob(vector<int>& nums) {
          int n=nums.size();
          if (n == 1) return nums[0];
    vector<int>temp1(n);
vector<int>temp2(n);
for (int i=0;i<n;i++){
if(i!=0) temp1.push_back(nums[i]);
if(i!=n-1) temp2.push_back(nums[i]);

}
return (max(solve(temp1),solve(temp2)));
    }
};