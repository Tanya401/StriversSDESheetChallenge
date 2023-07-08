bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathvis,int parent){
  vis[node]=1;
  pathvis[node]=1;

  for(auto it:adj[node]){
    if(!vis[it])
    {
      if(dfs(it,adj,vis,pathvis,node)==true) return true;
    }
    else if(pathvis[it]) return true;
  }

  pathvis[node]=0;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> adj[n+1];
  for(int i=0;i<edges.size();i++){
    adj[edges[i].first].push_back(edges[i].second);
  }
  vector<int> vis(n+1,0);
  vector<int> pathvis(n+1,0);

  for(int i=1;i<=n;i++){
    if(!vis[i])
    {
      if(dfs(i,adj,vis,pathvis,-1)==true) return 1;
    }
  }
  return 0;
}