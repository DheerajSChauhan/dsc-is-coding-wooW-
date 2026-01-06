class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int m = matrix.size();
        // int n = matrix[0].size();

        // int i =0;
        // int j =n-1;

        // while( i<m && j>=0){
        //     if(matrix[i][j]> target){
        //         j--;
        //     }else if(matrix[i][j]< target){
        //         i++;
        //     }else{
        //         return true;
        //     }
        // }
        // return false;


        //using 2D 
        int n = matrix.size();        // rows
        int m = matrix[0].size();     // cols

        int start = 0;
        int end = m * n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int row = mid / m;        // use m
            int col = mid % m;        // use m

            if (matrix[row][col] > target) {
                end = mid - 1;
            } else if (matrix[row][col] < target) {
                start = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};