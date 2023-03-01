
void insertAtbottom(stack<int> &stack,int num){

if(stack.empty()){
    stack.push(num);
    return;
}
else{
    int number=stack.top();
    stack.pop();
    insertAtbottom(stack,  num);
    stack.push(number);
}
}
void reverseStack(stack<int> &stack) {
 if(stack.empty()){
     return;
 }
int num=stack.top();
stack.pop();
reverseStack(stack);
insertAtbottom(stack,num);

}                