#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    // Write your code here.
     for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             int start = j+1, end = n-1;
             int temp = target - (arr[i]+arr[j]);
             while(start<end){
                 if(arr[start]+arr[end]>temp) end--;
                 else if(arr[start]+arr[end]<temp)start++;
                 else{
                          return "Yes";
                 }
             }
         }
     }
     return "No";
}
