#include <bits/stdc++.h> 
bool find(int ind,int k,vector<int>&arr,vector<vector<int>>&dp){
    if(k==0) return true;
    if(ind == 0) {
        if(arr[ind]==k) return true;
        return false;
    }
    if(dp[ind][k]!=-1) return dp[ind][k];
    bool take = false;
    if(arr[ind]<=k)
    take = find(ind-1,k-arr[ind],arr,dp);

    bool nottake = find(ind-1,k,arr,dp);

    return dp[ind][k] = take || nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return find(n-1,k,arr,dp);
}