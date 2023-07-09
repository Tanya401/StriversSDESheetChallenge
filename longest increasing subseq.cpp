#include<bits/stdc++.h>
int find(int ind,int arr[],int prev,vector<vector<int>>&dp){
    if(ind < 0) return 0;
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    int take = INT_MIN;
    if(prev == -1 || arr[ind] < arr[prev])
    take = 1 + find(ind-1,arr,ind,dp);

    int nottake = find(ind-1,arr,prev,dp);

    return dp[ind][prev+1] = max(take,nottake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    int prev = -1;
   int ans =  find(n-1,arr,prev,dp);
   return ans;
}
