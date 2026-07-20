class Solution {
public:
    bool checkBipartiteBFS(vector<vector<int>>& adj, int curr, vector<int>& color, int currColor){
        queue<int>q;
        q.push(curr);
        color[curr] = currColor;

        while(!q.empty()){
            int u = q.front();      
            q.pop();
            for(auto &v:adj[u]){
                if(color[v] == color[u])return false;
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int>color(V, -1); // no node is colored as of now
        //red = 1;
        //green = 0;
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(!checkBipartiteBFS(adj, i, color, 1))return false;
            }
        }
        return true;
    }
};