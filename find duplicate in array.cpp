#include <bits/stdc++.h>

int findDuplicate(vector<int> &nums, int n){
	// Write your code here.
	for(int i=0;i<n;i++){
		if(nums[abs(nums[i])-1] < 0 ) return abs(nums[i]);
		nums[abs(nums[i])-1] = -1*nums[abs(nums[i])-1];
	}
	return -1;
}
