class Solution {
  public:
    typedef pair<int, int> p;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        //creating a adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<p, vector<p>, greater<p>>pq;
        pq.push({0, 0});
        
        vector<bool>inMST(V, false);
        int sum = 0;
        
        while(!pq.empty()){
            auto  p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if(inMST[node] == true) continue;
            
            inMST[node] = true; //we will add this to inMST[];
            sum += wt;
            
            for(auto &temp: adj[node]){
                int neighbour = temp.first;
                int neighbour_wt = temp.second;
                
                if (inMST[neighbour] == false) {
                    pq.push({neighbour_wt, neighbour});
                }
            }
        }
        return sum;
    }
};