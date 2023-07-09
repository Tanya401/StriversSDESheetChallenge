int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> dist(n+1,vector<int>(n+1,1e9));
    for(int i=1;i<=n;i++) dist[i][i] = 0;
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int distance = it[2];
        dist[u][v] = distance;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=1e9 && dist[k][j]!=1e9)
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist[src][dest];
}