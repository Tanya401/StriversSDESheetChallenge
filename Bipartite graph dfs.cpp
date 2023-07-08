bool dfs(int node, vector<int>& col, vector<vector<int>>& graph, int color) {
    col[node] = color;

    for (int it = 0; it < graph.size(); it++) {
        if (graph[node][it] == 1) {
            if (col[it] == -1) {
                if (dfs(it, col, graph, 1 - color) == false)
                    return false;
            }
            else if (col[it] == color)
                return false;
        }
    }

    return true;
}

bool isGraphBirpatite(vector<vector<int>>& graph) {
    int v = graph.size();
    vector<int> col(v, -1);

    for (int i = 0; i < v; i++) {
        if (col[i] == -1) {
            if (dfs(i, col, graph, 0) == false)
                return false;
        }
    }

    return true;
}
