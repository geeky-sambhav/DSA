
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>visited;
        int left=0;
        int maxlength=0;
        for(int right=0;right<s.length();right++){
            if(visited.find(s[right])!=visited.end()){
                left=max(visited[s[right]]+1,left);

            }
            visited[s[right]]=right;
            maxlength=max(maxlength,right-left+1);


        }
        return maxlength;
    }
         
};