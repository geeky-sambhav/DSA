#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    if(q.size()%2 !=0)
        cout<<"even number of interges"<<endl;
    
    queue<int> temp;
    int halfSize= q.size()/2;
    
    for(int i=0;i<halfSize;i++){
        temp.push(q.front());
        q.pop();
    }
    
    while(!temp.empty()){
        q.push(temp.front());
        q.push(q.front());
        q.pop();
        temp.pop();
    }
}

