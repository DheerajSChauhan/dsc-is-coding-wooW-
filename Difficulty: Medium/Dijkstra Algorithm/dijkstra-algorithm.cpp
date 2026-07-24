class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> result(V, INT_MAX);

        result[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > result[node])
                continue;

            for (auto &vec : adj[node]) {

                int adjNode = vec.first;
                int wt = vec.second;

                if (d + wt < result[adjNode]) {
                    result[adjNode] = d + wt;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }
        return result;
    }
};