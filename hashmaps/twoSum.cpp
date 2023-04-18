class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>visited;
        for(int i=0;i<nums.size();i++){
            int more=target-nums[i];
            if(visited.find(more)!=visited.end()){
                return {visited[more],i};
            }
            else{
                visited[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};