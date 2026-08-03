class Solution {
public:
    void checkDFS(int u, unordered_map<int, vector<int>>& adj, vector<bool> &visited){
        visited[u] = true;
        for(auto &v: adj[u]){
            if(!visited[v]){
                checkDFS(v, adj, visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //using DFS

        unordered_map<int, vector<int>>adj;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n, false);

        checkDFS(source, adj, visited);

        return visited[destination];

    }
};