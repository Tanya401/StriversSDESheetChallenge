#include <bits/stdc++.h>
int find(int i,int j,vector<vector<int>>&dp){
	if(i<0 || j<0) return 0;

	if(i==0 && j==0) return 1;

	if(dp[i][j]!=-1) return dp[i][j];

	int left = find(i,j-1,dp);
	int up = find(i-1,j,dp);

	return dp[i][j] = (up+left);
} 
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m,vector<int>(n,-1));
	return find(m-1,n-1,dp);
}