class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); //row
        int n = matrix[0].size(); //column
        bool firstRowInput = false;
        bool firstColInput = false;

        //check for first row mein zero hai ya nahi
        for(int col=0; col<n; col++){
            if( matrix[0][col] == 0){
                firstRowInput =true;
                break;
            }
        }
        //check for column mein zero hai ya nahi
        for(int row =0; row<m; row++){
            if( matrix[row][0] ==0){
                firstColInput =true;
                break;
            }
        }
        //mark the first row and column 
        for(int i =1 ; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0]= 0;
                    matrix[0][j]= 0;
                }
            }
        }
        //set zero using marks
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0] ==0 || matrix[0][j]==0){
                    matrix[i][j] =0;
                }
            }
        }
        //first row
        if(firstRowInput == true){
            for(int j =0 ; j<n; j++){
                matrix[0][j]=0;
            }
        }
        if(firstColInput == true){
            for(int i=0; i<m; i++){
                matrix[i][0]=0;
            }
        }
    }
};