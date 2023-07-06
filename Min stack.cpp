#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int> s1,s2;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(s2.empty()) {
				s1.push(num);
				s2.push(num);
			}
			else{
				s1.push(num);
				if(s2.empty() || num <= s2.top()) s2.push(num);
			}
		}

		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(s1.empty()) return -1;
			int ans = -1;
			if(!s1.empty() && s1.top() == s2.top()) {
				ans = s1.top();
				s1.pop();
				s2.pop();
			}
			else{
				ans = s1.top();
				s1.pop();
			}
			return ans;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(s1.empty()) return -1;
			return s1.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(s2.empty()) return -1;
			return s2.top();
		}
};