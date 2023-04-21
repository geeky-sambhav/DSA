class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergedvectors;
        if (intervals.size()==0){
            return mergedvectors;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>temp=intervals[0];
        for(auto it:intervals){
            if(temp[1]>=it[0] ){
                temp[1]=max(temp[1],it[1]);
            }
            else{
                mergedvectors.push_back(temp);
                temp=it;
            }
            
        }
            mergedvectors.push_back(temp);
            return mergedvectors;
    }
};