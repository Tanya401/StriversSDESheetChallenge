#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, 
vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int,int>> adj[n];
    for(int i=0;i<g.size();i++){
       int u = g[i].first.first;
       int v = g[i].first.second;
       int w = g[i].second;
       adj[u-1].push_back({v-1,w});
       adj[v-1].push_back({u-1,w});
    }
    std::priority_queue<
    std::pair<std::pair<int, int>, int>,
    std::vector<std::pair<std::pair<int, int>, int>>,
    std::greater<std::pair<std::pair<int, int>, int>>
> pq;
    pq.push({{0,0},-1});
     vector<int> vis(n,0);
    vector<pair<pair<int,int>,int>> ans;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int weight = top.first.first;
        int node = top.first.second;
        int parent = top.second;
         if(vis[node]==1) continue;
        vis[node]=1;
        if(parent != -1){
            ans.push_back({{node+1,parent+1},weight});
        }
        for (auto it : adj[node]) {
        int adjnode = it.first;
         int w = it.second;

    if (!vis[adjnode])
        pq.push({{w, adjnode}, node});
}    
  }
   return ans;
}
