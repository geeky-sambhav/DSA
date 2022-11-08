class Solution {
    private:
    void solve(vector <string> &ans,string digits,int index,string mapping[],string output){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0';
        string value=mapping[number];
        for(int i=0;i<value.length();i++){
           output.push_back(value[i]);
           solve(ans,digits,index+1,mapping,output);
           output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
         vector<string> ans;
        if (digits.length()==0){
    return ans;
}
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       
        string output="";
        solve (ans,digits,0,mapping,output);

        return ans;
    }
};