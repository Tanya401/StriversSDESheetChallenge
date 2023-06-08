#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int ele = 0, cnt = 0;
	for(int i=0;i<n;i++){
     if(cnt == 0){
		 ele = arr[i];
		 cnt++;
	 }
	 else if(arr[i] == ele) cnt++;
	 else cnt--;
	}
	int temp = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == ele) temp++;
	}
	if(temp > n/2) return ele;
	return -1;
}