class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        visited[u] = true;

        for(auto &v: adj[u]){ 
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        unordered_map<int, vector<int>>adj;

        for(int i=0; i<n; i++){
            for(int key: rooms[i]){
                adj[i].push_back(key);
            }
        }
        vector<bool>visited(n, false);

        dfs(0, adj, visited);
    
        //check if all room are visited
        for(auto room: visited){
            if(!room){
                return false;
            }
        }
        return true;
    }
};