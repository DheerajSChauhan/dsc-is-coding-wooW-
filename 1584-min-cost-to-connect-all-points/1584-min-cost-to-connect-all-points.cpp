class Solution {
public:
    typedef pair<int, int> p;

    int primAlgo(vector<vector<p>>& adj, int V) {

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});

        vector<bool> isMST(V, false);
        int sum = 0;

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int wt = curr.first;
            int node = curr.second;

            if (isMST[node])
                continue;

            isMST[node] = true;
            sum += wt;

            for (auto &tmp : adj[node]) {

                int neighbor = tmp.first;
                int neighbor_wt = tmp.second;

                if (!isMST[neighbor]) {
                    pq.push({neighbor_wt, neighbor});
                }
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();
        vector<vector<p>> adj(V);

        for (int i = 0; i < V; i++) {

            for (int j = i + 1; j < V; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x2 - x1) + abs(y2 - y1);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        return primAlgo(adj, V);
    }
};