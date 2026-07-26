class Solution {
public:
    vector<vector<int>>directions{{1,0}, {0,1}, {1,1}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //using BFS:
        int m = grid.size();
        int n = grid[0].size();

        //if matrix has no row or no column or if the (0,0) is not equal to 0 then we can't solve the question 
        if(m == 0 || n == 0 || grid[0][0] != 0) return -1;

        auto isSafe = [&](int x, int y){
            return(x >= 0 && x < m && y >= 0 && y < n );
        };
        queue<pair<int, int>>que;

        que.push({0,0});
        grid[0][0] = 1;
        int level = 0;

        while(! que.empty()){
            int size = que.size();

            while(size--){
                auto curr = que.front();
                que.pop();

                int x = curr.first;
                int y = curr.second;

                if(x == m-1 && y == n-1){
                    return level+1;
                }

                for(auto &dir: directions){
                    int x_ = x + dir[0]; 
                    int y_ = y + dir[1];

                    //use toh kar rahe hai har dierction kya vo safe hai use bhe check kar lenge
                    if(isSafe(x_, y_) && grid[x_][y_] == 0){
                        que.push({x_, y_});
                        grid[x_][y_] = 1;
                    }
                }   
            }
            level++;
        }
        return -1;
    }
};