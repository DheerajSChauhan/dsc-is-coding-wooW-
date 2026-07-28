class Solution {
public:
    int n;

    void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;
        for(auto &v: adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        n = isConnected.size();

        //make graph
        unordered_map<int, vector<int>>adj;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n, false);
        int Provinvescount =0;
        for(int u=0; u<n; u++){
            for(auto &v: adj[u]){
                if(!visited[v]){
                    DFS(adj, u, visited);
                    Provinvescount++;
                }
            }
        }
        return Provinvescount;
    }
};