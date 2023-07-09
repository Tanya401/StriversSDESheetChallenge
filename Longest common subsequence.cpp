#include<bits/stdc++.h>
int find(int i,int j,string s,string t,vector<vector<int>>&dp){
  if(i<0 || j<0) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  int take = INT_MIN;
  if(s[i]==t[j])
  take = 1+find(i-1,j-1,s,t,dp);

  int nottake = max(find(i,j-1,s,t,dp),find(i-1,j,s,t,dp));

  return dp[i][j] = max(take,nottake);
}
int lcs(string s, string t)
{
	//Write your code here
	int n = s.size();
	int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	// int ans = find(n-1,m-1,s,t,dp);
	// return ans;
	for(int i=0;i<=n;i++) dp[i][0] = 0;
	for(int i=0;i<=m;i++) dp[0][i] = 0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		int take = INT_MIN;
  if(s[i-1]==t[j-1])
  take = 1+dp[i-1][j-1];

  int nottake = max(dp[i][j-1],dp[i-1][j]);

   dp[i][j] = max(take,nottake);
		}
	}
	return dp[n][m];
}