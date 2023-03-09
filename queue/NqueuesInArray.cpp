#include <bits/stdc++.h> 
class NQueue{
public:
int *arr;
int *front;
int *rear;
int *next;
int freeSpot;
int n;
int s;

    // Initialize your data structure.
    NQueue(int n, int s){
        this->n=n;
        this->s=s;
        arr=new int[s];
        next=new int[s];        ;
        front=new int[n];
        rear=new int[n];
        freeSpot=0;
        for (int i=0;i<n;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        
        for (int i=0;i<s;i++){
            next[i]=i+1;
        }
        next[s-1]=-1;
    }
    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Write your code here.

        if(freeSpot==-1){
            return false;

        }
int index=freeSpot;
freeSpot=next[index];
        //check starting 
        if(front[m-1]==-1){
            front[m-1]=index;
        }
        else{
            next[rear[m-1]]=index;

        }
    //update next
    next[index]=-1;
    //update rear
    rear[m-1]=index;
    //push
    arr[index]=x;
return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
  if (front[m-1]==-1){
      return -1;
  }
 int index=front[m-1];
 
  front[m-1]=next[index];
  next[index]=freeSpot;
  freeSpot=index;
  return arr[index];
    }
};