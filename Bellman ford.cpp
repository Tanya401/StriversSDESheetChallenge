#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    //create graph and then find smallest distance n-1 times
   vector<int> dist(n+1,1e9);
   queue<pair<int,int>> q;
   dist[src]=0;
   q.push({src,0});
   for(int i=1;i<=n;i++){
      while(!q.empty()){
          auto top = q.front();
          q.pop();
          int node = top.first;
          int dis = top.second;
          for(auto it:adj[node]){
              int adjnode = it.first;
              int distance = it.second;
              if(dis + distance < dist[adjnode]){
                  dist[adjnode] = dis+distance;
                  q.push({adjnode,dist[adjnode]});
              }
          }
      }
   }
   return dist[dest];
}