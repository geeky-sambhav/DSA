// TBTK POP KRTE JAO JBTK QUEUE EMPTY NA HO JAYE INCASE OF REPEATING ELEMENT AND WHEN QUEUE IS EMPTY INSERT#

class Solution {
	public:
		string FirstNonRepeating(string A){
queue<char>q;
string ans;
unordered_map<char,int>counter;
for(int i=0;i<A.length();i++){
    counter[A[i]]++;
    q.push(A[i]);
    while(!q.empty()){
        if(counter[q.front()]>1){
            q.pop();
        }
        else{
            ans.push_back(q.front());
            break;
        }
    }
    if(q.empty()){
        ans.push_back('#');
    }
}
return ans;
		}

};