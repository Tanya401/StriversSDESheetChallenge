#include<bits/stdc++.h>
void dfs(int i,int j,int n,int m,int **arr,vector<vector<int>>&vis){
   if(i<0 || j<0 || i>=n || j>=m) return;

   if(arr[i][j]==0 || vis[i][j]==1) return;

   if(arr[i][j]==1 && !vis[i][j]){
      vis[i][j]=1;
      dfs(i+1,j,n,m,arr,vis);
      dfs(i-1,j,m,n,arr,vis);
      dfs(i,j+1,n,m,arr,vis);
      dfs(i,j-1,n,m,arr,vis);
      dfs(i+1,j+1,n,m,arr,vis);
      dfs(i+1,j-1,n,m,arr,vis);
      dfs(i-1,j+1,n,m,arr,vis);
      dfs(i-1,j-1,n,m,arr,vis);
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   vector<vector<int>> vis(n,vector<int>(m,0));
   int islands = 0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(arr[i][j]==1 && !vis[i][j]){
            dfs(i,j,n,m,arr,vis);
            islands++;
         }
      }
   }
   return islands;
}
