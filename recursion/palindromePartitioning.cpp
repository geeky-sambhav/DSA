class Solution {
public:
bool isPalindrome(int start,int end,string s){
while(start<=end){
    if(s[start++]!=s[end--]){
        return false;
    }
}
return true;


}

    void solve(int index,string s,vector<vector<string>>&ans,vector<string>&path){
if(index>=s.size()){
    ans.push_back(path);
    return ;
}
for (int i=index;i<s.size();i++){
    if(isPalindrome(index,i,s)){
        path.push_back(s.substr(index,i-index+1));
        solve(i+1,s,ans,path);
        path.pop_back();
    }

}


    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(0,s,ans,path);
        return ans;
    }
};