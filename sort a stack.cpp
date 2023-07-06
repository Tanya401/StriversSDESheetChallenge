//imp
#include <bits/stdc++.h> 
void insert(stack<int>&stack,int ans){
	if(stack.empty() || stack.top()<ans){
		stack.push(ans);
		return;
	}
	int n = stack.top();
	stack.pop();

	insert(stack,ans);

	stack.push(n);
}
void find(stack<int>&stack){ 
     if(stack.empty()) return;

	 int ans = stack.top();
	 stack.pop();
	 find(stack);

	 insert(stack,ans);

}
void sortStack(stack<int> &stack)
{
	// Write your code here
   find(stack);
}