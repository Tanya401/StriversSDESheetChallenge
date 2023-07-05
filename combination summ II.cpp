#include<bits/stdc++.h>
void find(int ind,int n,vector<int>&arr,int target,vector<vector<int>>&ans,vector<int>temp){
   if(target == 0){
		ans.push_back(temp);
		return;
	}
    for(int i=ind;i<n;i++){
		if(i>ind && arr[i]==arr[i-1]) continue;
		  if (arr[i] > target) break;
		if(arr[i]<=target)
		{
			temp.push_back(arr[i]);
			find(i+1,n,arr,target-arr[i],ans,temp);
			temp.pop_back();
		}
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<vector<int>> ans;

	vector<int> temp;

	if(arr.empty()) return ans;
    
	sort(arr.begin(),arr.end());

	find(0,n,arr,target,ans,temp);

	return ans;

}

