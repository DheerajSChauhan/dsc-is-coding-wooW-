class Solution {
public:
    bool checkDFS(int u, int dest, unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        if( u == dest){
            return true;
        }        
        visited[u] = true;
        for(auto &v: adj[u]){
            if(!visited[v]){
                if(checkDFS(v, dest, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int V = edges.size();

        unordered_map<int, vector<int>>adj;
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            vector<bool>visited(V, false);

            //if u and v are already connected;
            //then current edge is redundant;
            if( checkDFS(u, v, adj, visited)){
                return edge;
            }

            //otherwise add the edge

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
        
    }
};