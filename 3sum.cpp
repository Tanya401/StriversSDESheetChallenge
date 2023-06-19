#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
      int target = K-arr[i];
      int start = i+1,end=n-1;
      while(start<end){
          if(arr[start]+arr[end]<target) start++;
          else if(arr[start]+arr[end]>target) end--;
          else{
              vector<int> temp(3,0);
              temp[0]=arr[i];
              temp[1] = arr[start];
              temp[2]=arr[end];
              ans.push_back(temp);
              while(start<end && arr[start]==temp[1]) ++start;
              while(start<end && arr[end]==temp[2]) --end;
          }
      }
      while(i+1<n && arr[i]==arr[i+1]) ++i;  
    }
    return ans;
}