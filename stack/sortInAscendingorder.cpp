void insertsort(stack<int> &s,int num){
    if(s.empty() ){
        s.push(num);
        return;
    }
    else if(s.top()>num){
        
    int pop=s.top();
    s.pop();
    insertsort(s,num);
        s.push(pop);
    }
    else{
    s.push(num);}
}
void SortedStack :: sort()
{
    if(s.empty()){
        return;
    }
int num=s.top();
s.pop();
sort();
insertsort(s,num);
}