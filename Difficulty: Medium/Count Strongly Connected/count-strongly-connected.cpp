class Solution {
  public:
    void dfsFill(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
        visited[u] = true;
        for(int &v: adj[u]){
            if(!visited[v]){
                dfsFill(v, adj, visited , st);
            }
        }
        st.push(u);
    }
    
    void dfsTraversal(int u, vector<vector<int>>& adjReversed, vector<bool>& visited){
        visited[u] = true;
        for(int &v: adjReversed[u]){
            if(!visited[v]){
                dfsTraversal(v, adjReversed, visited);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        // step1:DFS call
        vector<bool>visited(V, false);
        stack<int>st;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfsFill(i, adj, visited, st);
            }
        }
        
        //step 2: make a reverse graph:
        
        vector<vector<int>>adjReversed(V);
        for(int u =0; u<V; u++){
            for(int &v: adj[u]){
                adjReversed[v].push_back(u);
            }
        }
        
        //step 3: call dfs based on stack order:
        
        int countSCC = 0;
        visited = vector<bool>(V,false);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                dfsTraversal(node, adjReversed, visited);
                countSCC++;
                
            }
        }
        return countSCC;
    }
};