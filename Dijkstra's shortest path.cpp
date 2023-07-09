#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>> adj[vertices];
    for(int i=0;i<vec.size();i++){
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
   vector<int> dist(vertices,INT_MAX);
   dist[0]=0;
   queue<pair<int,int>> q;
   q.push({0,0});
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
   vector<int> ans;
   for(int i=0;i<vertices;i++){
       ans.push_back(dist[i]);
   }
   return ans;
}
