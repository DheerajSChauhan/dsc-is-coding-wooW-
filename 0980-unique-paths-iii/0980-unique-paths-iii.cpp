class Solution {
public:
    int result;
    int nonObstacle;
    int m,n;
    vector<vector<int>>directions = { {0,1}, {0,-1}, {1,0}, {-1,0}};
    void backtrack(vector<vector<int>>& grid, int count, int i, int j){
        if( i<0 || j<0 || i>=m || j>=n || grid[i][j] == -1){
            return ;
        }
        if( grid[i][j] == 2){
            if(nonObstacle == count){
                result++;
            }
            return;
        }
        int temp =grid[i][j];
        grid[i][j] =-1;
        for( auto dir : directions){
            int new_x = i + dir[0];
            int new_y = j + dir[1];

            backtrack(grid, count + 1, new_x, new_y);
        }
        grid[i][j] = temp;
    }



    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int start_i =0;
        int start_j =0;
        nonObstacle =0;
        int count =0;
        result =0;
        for(int i=0; i<m; i++){
            for( int j=0; j<n; j++){
                if(grid[i][j] == 0 ){
                    nonObstacle++;
                }
                if( grid[i][j] == 1){
                    start_i = i;
                    start_j = j;
                }
            }
        }
        nonObstacle+=1;

        backtrack( grid, count, start_i, start_j);
        return result;
    }
};