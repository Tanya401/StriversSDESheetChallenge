#include <bits/stdc++.h> 
int find(int ind,vector<int>&rack,int n,int prev,vector<vector<int>>&dp){
      if(ind == n) return 0;
	  if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
     int take = INT_MIN;
	if(prev == -1 || rack[prev] < rack[ind])
	take = rack[ind] + find(ind+1,rack,n,ind,dp);

	int nottake = find(ind+1,rack,n,prev,dp);

	return dp[ind][prev+1] = max(take,nottake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
  int ans=rack[0];
       vector<int>dp=rack;
       for (int i=1;i<n;i++)
       {
           for (int j=0;j<i;j++)
           {
               if (rack[i]>rack[j])
               {
                   if (dp[j]+rack[i]>dp[i])
                   {
                       dp[i]=dp[j]+rack[i];
                   }
               }
           }
           ans=max(ans,dp[i]);
       }
       return ans;

}