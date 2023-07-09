#include<bits/stdc++.h>
int find(int ind, int w, vector<int> &values, vector<int> &weights,vector<vector<int>>&dp) {
  if(ind == 0){
	  if (weights[0] <= w)
            return values[0];
        return 0;
  }
  
  if(dp[ind][w]!=-1) return dp[ind][w];

  int take = INT_MIN;
  if (weights[ind] <= w)
  take = values[ind] + find(ind-1,w-weights[ind],values,weights,dp);

  int nottake = find(ind-1,w,values,weights,dp);

  return dp[ind][w] = max(take,nottake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(w+1,0));
	//return find(n-1,w,values,weights,dp);
	for(int i=weights[0];i<=w;i++) dp[0][i] = values[0];

	for(int i=1;i<n;i++){
	 for(int we=0;we<=w;we++){
		int take = INT_MIN;
  if (weights[i] <= we)
  take = values[i] + dp[i-1][we-weights[i]];

  int nottake = dp[i-1][we];

 dp[i][we] = max(take,nottake);
	 }
	}
	return dp[n-1][w];
}