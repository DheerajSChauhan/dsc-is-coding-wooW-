class Solution {
public:
    vector<int>rank;
    vector<int>parent;

    int find(int x){
        if(x == parent[x]){
            return x; 
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent){
            return;
        }
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[y_parent] = x_parent;
            rank[y_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);

        //agar connection , n-1 se kam he toh possible he nahi hoga
        if(connections.size() < n-1){
            return -1;
        }

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int components = n; //ilaka
        for(auto &v: connections){
            if(find(v[0]) != find(v[1])){
                Union(v[0], v[1]);
                components--;
            }
        }
        return components -1;
    }
};