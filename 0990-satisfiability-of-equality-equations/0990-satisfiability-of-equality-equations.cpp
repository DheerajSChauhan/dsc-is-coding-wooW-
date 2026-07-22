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

        if(x_parent == y_parent)return;

        if(rank[x_parent] > rank[y_parent]) parent[y_parent] = x_parent;
        else if(rank[x_parent] < rank[y_parent]) parent[x_parent] = y_parent;
        else{
            parent[y_parent] = x_parent; 
            rank[y_parent]++;
        } 
    
    }
    bool equationsPossible(vector<string>& equations) {
        rank.resize(26,0);
        parent.resize(26);

        for(int i=0; i<26; i++){
            parent[i] = i;
        }

        //first do union of same char
        // a = = b
        // 0 1 2 3
        for(auto &s: equations){
            if(s[1] == '='){ //for a == b
                Union(s[0] - 'a', s[3] - 'a');
            }
        }
        // find != wale  and check the validty
        for(auto &s: equations){
            if(s[1] == '!'){ // a != b
                char first = s[0]; //a
                char second = s[3]; //b

                int parent_first = find(first - 'a');
                int parent_second = find(second - 'a');

                if(parent_first == parent_second){
                    return false;
                }
            }
        }
        return true;
    }
};