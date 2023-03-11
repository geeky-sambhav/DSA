//  SBSE PEHLE SORT KRO (NLOGN)
//   FIRST ARRAY PUSH KRLO VECTOR MEIN FIR USKA SECOND ELEMENT COMPARE KRO SECOND VECTOR KE SATH AGR SECOND ELEMENT BDA HAI TO MERGE KRO NHI O SECOND VECTOR KO BHI PUSH KRDO

class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         if(intervals.size()==0){
             return intervals;
         }
          sort(intervals.begin(), intervals.end());
         vector<vector<int>>ans;
        ans.push_back(intervals[0]);
         for(int i=1;i<intervals.size();i++){
             if(ans.back()[1]>=intervals[i][0]){
                 ans.back()[1]=max(ans.back()[1],intervals[i][1]);
             }
             else{
                 ans.push_back(intervals[i]);
             }
         }
         return ans;
    }
};