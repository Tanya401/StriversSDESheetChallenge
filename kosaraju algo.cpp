#include<bits/stdc++.h>
void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&st){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]) dfs(it,vis,adj,st);
    }
    st.push(node);
}
void find(int node,vector<int>&vis,vector<int> adjt[],vector<int>&temp){
    vis[node]=1;
    temp.push_back(node);
    for(auto it:adjt[node]){
        if(!vis[it]) find(it,vis,adjt,temp);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i])
        dfs(i,vis,adj,st);
    }
    vector<int> adjt[n];
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(auto it:adj[i]){
            adjt[it].push_back(i);
        }
    }
    vector<vector<int>> ans;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if (!vis[node]) {
          vector<int> temp;
          find(node, vis, adjt, temp);
          ans.push_back(temp);
        }
    }
    return ans;
}