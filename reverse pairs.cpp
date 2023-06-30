#include <bits/stdc++.h> 
int merge(int start,int mid,int end,vector<int>&arr){
	int count = 0;
	vector<int> temp;
	int left = start, right = mid+1;
	int j = mid+1;
	for(int i=start;i<=mid;i++){
		while(j<=end && arr[i]>2*arr[j]) j++;
		count += (j-(mid+1));
	}
	while(left<=mid && right<=end){
		if(arr[left]<=arr[right]){
			temp.push_back(arr[left++]);
		}
		else{
			temp.push_back(arr[right++]);
		}
	}
	while(left<=mid){
		temp.push_back(arr[left++]);
	}
	while(right<=end){
		temp.push_back(arr[right++]);
	}
	for(int i=start;i<=end;i++){
		arr[i] = temp[i-start];
	}
	return count;
}
int mergesort(int start,int end,vector<int>&arr){
	int count = 0;
	if(start>=end) return count;

	int mid = (start+end)/2;
	count += mergesort(start,mid,arr);
	count += mergesort(mid+1,end,arr);
	count += merge(start,mid,end,arr);

	return count;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	int start = 0;
	int end = n-1;
	return mergesort(start,end,arr);	
}