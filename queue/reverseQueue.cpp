// WE WILL USE STACK TO REVERSE IN O(N)
// IN RECURSION IT WILL TAKE O(N2)

queue<int> rev(queue<int> q)
{   
    stack<int>s1;
    while(!q.empty()){
        s1.push(q.front());
        q.pop();
            }
    while(!s1.empty()){
        q.push(s1.top());
      s1.pop();
    }
    return q;
}