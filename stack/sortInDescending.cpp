#include <bits/stdc++.h> 
void insertSorted(stack<int> &stack,int num){
	if(stack.empty() ||(!stack.empty() && stack.top()<num)){
		stack.push(num);
		return;
	}
	int i=stack.top();
	stack.pop();
	insertSorted(stack,num);
	stack.push(i);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	insertSorted(stack,num);
}