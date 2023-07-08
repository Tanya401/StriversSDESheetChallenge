void dfs(int node,vector<int>adj[],vector<int>&temp,vector<int>&vis){
  vis[node]=1;
  temp.push_back(node);
  for(auto it:adj[node]){
    if(!vis[it])
    dfs(it,adj,temp,vis);
  }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    for(int i=0;i<E;i++){
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> ans;
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
      if(vis[i]==0){
        vector<int> temp;
        dfs(i,adj,temp,vis);
        ans.push_back(temp);
      }
    }
    return ans;
}