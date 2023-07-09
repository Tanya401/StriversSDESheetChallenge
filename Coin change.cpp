#include<bits/stdc++.h>
long find(int ind,int *denominations,int value,vector<vector<int>>&dp){
    if(ind == 0){
        if(value % denominations[0] == 0) return 1;
        return 0;
    }
    if(dp[ind][value]!=-1) return dp[ind][value];
    long take = 0;
    if(denominations[ind]<=value)
    take = find(ind,denominations,value-denominations[ind],dp);

    long nottake = find(ind-1,denominations,value,dp);

    return dp[ind][value] = take+nottake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long long>> dp(n,vector<long long>(value+1,0));
   // return find(n-1,denominations,value,dp);
   for(int v=0;v<=value;v++)
   {
       if(v%denominations[0]==0) dp[0][v] = 1;
   }
   for(int ind = 1;ind<n;ind++){
       for(int v=0;v<=value;v++){
        long take = 0;
    if(denominations[ind]<=v)
    take = dp[ind][v-denominations[ind]];

    long nottake = dp[ind-1][v];

     dp[ind][v] = take+nottake;  
       }
   }
   return dp[n-1][value];
}