#include <bits/stdc++.h> 
int find(int i,int j,vector<vector<int>>&grid,int n,int m,vector<vector<int>>&dp){
    if(i==0 && j==0) return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = INT_MAX;
    if(i-1>=0)
    up = grid[i][j] + find(i-1,j,grid,n,m,dp);

    int left = INT_MAX;
    if(j-1>=0)
    left = grid[i][j] + find(i,j-1,grid,n,m,dp);

    return dp[i][j] = min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();

   vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[n-1][m-1];
}