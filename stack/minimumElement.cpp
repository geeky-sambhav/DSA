// FOR PUSHING 
// IF CURR<MIN THEN NEW MIN=2*CURR-1
// FOR POPPING 
// IF STACK[TOP]<MIN , NEW MIN= 2*MIN-CURR
// THIS IS DONE TO GET THE PREVIOUS VALE  from current MINIMIMUM



#include<stack>
class SpecialStack {
    // Define the data members.
    stack<int>s1;
    int min;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        if(s1.empty()){
            s1.push(data);
            min=data;
        }
        else{
            if(data<min){
                s1.push(2*data-min);
                min=data;
            }
            else{
                s1.push(data);
            }
        }
    }

    int pop() {
            if (s1.empty()){
                return -1;
            }

        int curr=s1.top();
        s1.pop();
        if(curr<min){
            int prevmin=min;
            min=2*min-curr;
            return prevmin;
        }
        else{
            return curr;
        }
    }

    int top() {
        if(s1.empty()){
            return -1;
        }
        if(s1.top()>min){
            return s1.top();
        }
        else{
            return min;
        }
    }

    bool isEmpty() {
       return s1.empty();
    }

    int getMin() {
        if(s1.empty()){
            return -1;
        }
      return min;
    }  
};