#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int left = 1, right = 1;
	int prod = 1, maxprod = INT_MIN;
	for(int i=0;i<n;i++){
		if(left == 0) left = 1;
		if(right == 0) right = 1;
		left = left*arr[i];
		right = right*arr[n-1-i];
		maxprod = max(maxprod,max(left,right));
	}
	return maxprod;
}
