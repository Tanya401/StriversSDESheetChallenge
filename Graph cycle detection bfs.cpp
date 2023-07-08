#include<bits/stdc++.h>
bool bfs(int node,vector<int>adj[],queue<pair<int,int>>&q,vector<int>&vis){
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int node = front.first;
        int parent = front.second;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) q.push({it,node});
            else if(parent!=it) return true;
        }
    }
 return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    queue<pair<int,int>> q;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            q.push({i,-1});
           if(bfs(i,adj,q,vis)==true)
           return "Yes";
        }
    }
 return "No";
}
