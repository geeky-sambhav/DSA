PEHLE FIRST QUEUE MEIN PUSH KRO
JBTK 2ND QUEUE EMPTY NHI HO JAAT TBTK 2ND QUEUE KE ELEMENTS 1ST MEIN PUSH KRO
SWAP KRDO


void QueueStack :: push(int x)
{
      q1.push(x);
      while(!q2.empty()){
          q1.push(q2.front());
          q2.pop();
      }
      swap(q1,q2);
      
      
   

}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
   
        // Your Code       
        
        
         if(q2.empty())
        return -1;
        int ans = q2.front();
        q2.pop();
        return ans;
}
