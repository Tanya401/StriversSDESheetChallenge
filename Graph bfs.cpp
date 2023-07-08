#include <bits/stdc++.h> 

void bfs(int node, queue<int>& q, vector<int> adj[], vector<int>& ans, vector<int>& vis){
    while(!q.empty()){
        int currNode = q.front();
        q.pop();
        ans.push_back(currNode);
        vis[currNode] = 1;
        for(auto it : adj[currNode]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1; // Update visited array before pushing into the queue
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    vector<int> adj[vertex];
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<vertex;i++){
    sort(adj[i].begin(),adj[i].end());
    }
    vector<int> vis(vertex, 0);
    queue<int> q;
    vector<int> ans;
    for(int i = 0; i < vertex; i++){
        if(!vis[i]){
            q.push(i);
            bfs(i, q, adj, ans, vis);
        }
    }
    return ans;
}
