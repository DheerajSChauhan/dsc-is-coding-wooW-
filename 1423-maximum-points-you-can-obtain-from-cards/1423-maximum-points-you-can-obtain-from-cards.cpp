class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0; 
        int rsum = 0;
        int maxSum = 0;
        for( int i = 0 ; i < k ; i++){
            lsum = lsum + cardPoints[i];
        }
        maxSum = lsum;
        int rightIndex = cardPoints.size()-1;
        for(int i = k-1 ; i >= 0 ; i--){
            rsum = rsum + cardPoints[rightIndex];
            lsum = lsum - cardPoints[i];
            rightIndex--;
            maxSum = max(maxSum , rsum + lsum);
        }
        return maxSum;
    }
};