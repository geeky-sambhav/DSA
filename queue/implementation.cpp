#include <bits/stdc++.h> 
class Queue {
        int rear;
        int qfront;
        int* arr;
        int size; 
public:
    Queue() {
        size=100001;
        arr=new int[size];
        rear=0;
        qfront=0;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
       if(rear==size-1){
           return;
       }
       arr[rear]=data;
       rear=rear+1;
    }

    int dequeue() {
        
        if(qfront==rear){
            return -1;
        }
        int ans=arr[qfront];
        arr[qfront]=-1;
        qfront++;
        if(qfront==rear){
            qfront=0;
            rear=0;
        }
        return ans;
        // Implement the dequeue() function
    }

    int front() {
        if(qfront==rear){
            return -1;
        }
      return arr[qfront];
      // Implement the front() function
    }

};