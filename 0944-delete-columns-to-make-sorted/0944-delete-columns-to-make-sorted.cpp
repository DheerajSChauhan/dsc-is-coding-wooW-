class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(); //number of rows
        int k = strs[0].size(); //number of columns

        int count = 0;

        for( int i =0; i<k; i++){ //column
            for( int j =1; j<n; j++){ //row
                if( strs[j][i] < strs[j-1][i]){
                    count++;
                    break; // delete this column
                }
            }
        }
        return count;
    }
};