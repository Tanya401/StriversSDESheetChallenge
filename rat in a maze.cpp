#include <bits/stdc++.h> 
void find(int i,int j,vector<vector<int>>&maze,vector<vector<int>>&ans,int n,
vector<vector<int>>&vis){
   if(i<0 || j<0 || i>=n || j>=n ) return ;
   if(vis[i][j]==1 || maze[i][j]==0) return;
   
   if(i==n-1 && j==n-1){
     vector<int> temp;
     vis[i][j]=1;
     for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
          temp.push_back(vis[i][j]);
       }
     }
     vis[i][j]=0;
     ans.push_back(temp);
     return;
   }

  
     vis[i][j]=1;

     find(i+1,j,maze,ans,n,vis);
     find(i-1,j,maze,ans,n,vis);
     find(i,j-1,maze,ans,n,vis);
     find(i,j+1,maze,ans,n,vis);

    vis[i][j]=0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
     // Write your code here.
     vector<vector<int>> vis(n,vector<int>(n,0));
     vector<vector<int>> ans;
     if(maze[0][0]==0) return ans;
     find(0,0,maze,ans,n,vis);
     return ans;
}