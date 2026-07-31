class Solution {
public:

    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        visited[u] = true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                DFS(adj, v, visited);
            }
        }
    }

    bool isConnected(int V, vector<vector<int>>& adj) {

        int nonZeroDegreeVertex = -1;

        for (int i = 0; i < V; i++) {
            if (adj[i].size() != 0) {
                nonZeroDegreeVertex = i;
                break;
            }
        }

        // No edges in graph
        if (nonZeroDegreeVertex == -1)
            return true;

        vector<bool> visited(V, false);

        DFS(adj, nonZeroDegreeVertex, visited);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && adj[i].size() > 0)
                return false;
        }

        return true;
    }

    int isEulerCircuit(int V, vector<vector<int>>& adj) {

        if (!isConnected(V, adj))
            return 0;

        int oddDegreeCount = 0;

        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0)
                oddDegreeCount++;
        }

        if (oddDegreeCount > 2)
            return 0;   // Not Eulerian
        else if (oddDegreeCount == 2)
            return 1;   // Euler Path
        else
            return 2;   // Euler Circuit
    }
};