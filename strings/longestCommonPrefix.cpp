class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs[0].size();
        string ans="";
        string first=strs[0];
        string last=strs[strs.size()-1];
        for (int i=0;i<n;i++){
            if(first[i]==last[i]){
                ans.push_back(first[i]);
            }
            else{
                break;
            }
        }
        return ans;
    }
};
