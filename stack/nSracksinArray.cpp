// IN CASE OF N STACKS IN AN ARRAY
// NEXT ARRAY WILL FIRST POINT TO NEXT EMPTY SPACE 
// AFTER PUSHING ELEMENT NEXT WILL POINT TO AGR ELEMENT DELETE HO GYA TO KONSA REH JAYEGA



#include <bits/stdc++.h> 
class NStack
{
public:
    // Initialize your data structure.
    int *arr;
        int n,s;
        int *next;
    int *top;
    int freeSpot;
    NStack(int N, int S)
    {
        n=N;
        s=S;
        arr=new int[s];
        top=new int[n];
        next=new int[s];
        for (int i=0;i<n;i++){
            top[i]=-1;
        }
        for(int i=0;i<s;i++){
            next[i]=i+1;
        }
        next[s-1]=-1;
        freeSpot=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check if it full
        if(freeSpot==-1){
            return false;
        }
        int i=freeSpot;
        //pushing value
        arr[i]=x;
        //updating freespot
        freeSpot=next[i];
        //Now next will point to agr top ko remove kr denge to konsa 
        //element bachega
        next[i]=top[m-1];
        //updating top element
        top[m-1]=i;
        return true;


    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    { //reverse the push statement
        if(top[m-1]==-1){
            return -1;
        } 
        int i=top[m-1];
        
     
        top[m-1]=next[i];
        next[i]=freeSpot;
        freeSpot=i;
        return arr[i];
      
    }
};