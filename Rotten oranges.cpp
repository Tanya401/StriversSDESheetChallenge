#include<queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int time = 0;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2) q.push({i,j});
        }
    }
    q.push({-1,-1});
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        int i = top.first;
        int j = top.second;
       if(i == -1 && j == -1) {
            if(!q.empty()) {
                time++;
                q.push({-1, -1}); // Marker for the next time step
            }
        }
        else{
         if(i+1<n && grid[i+1][j]==1){
             grid[i+1][j]=2;
             q.push({i+1,j});
         }
         if(i-1>=0 && grid[i-1][j]==1){
             grid[i-1][j]=2;
             q.push({i-1,j});
         }
         if(j+1<m && grid[i][j+1]==1){
             grid[i][j+1]=2;
             q.push({i,j+1});
         }
         if(j-1>=0 && grid[i][j-1]==1){
             grid[i][j-1]=2;
             q.push({i,j-1});
         }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1) return -1;
        }
    }
    return time;
}


