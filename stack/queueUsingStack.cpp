// PUSH TO NORMAL PUSH KRNA
// IN CASE OF POP AGR S2 KHALI HAI TO SARE ELEMENTS USME DAALDO TAKI REVERSE HO JAYE AUR POP KRTE JAO


void StackQueue :: push(int x)
{
    s1.push(x);
    
    // Your Code
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s2.empty()){
        if(s1.empty()){
            return -1;
        }    
        while(!s1.empty()){
            int num=s1.top();
            s1.pop();
            s2.push(num);
        }}
     int a=s2.top();
     s2.pop();
     return a;
        
    }