#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int n = arr.size();
  int ans = 0,sum = 0;
  for(int i=0;i<n;i++){
    sum = 0;
   for(int j=i;j<n;j++){
     sum += arr[j];
     if (sum == 0) {
       int len = j - i + 1;
       ans = max(ans, len);
     }
   }
  }
 return ans;
}