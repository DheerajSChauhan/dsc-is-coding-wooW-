class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0; //left pointer
        int r = n - 1; //right pointer
        int k = n - 1; // ans last se fill karte rahenge kyuki largest hamesa last mein he hoga
        vector<int>ans(n);

        while( l <= r){
            int rightSq = nums[r] * nums[r];
            int leftSq = nums[l] * nums[l];

            if(leftSq > rightSq){
                ans[k] = leftSq;
                l++;
            }else{
                ans[k] = rightSq;
                r--;
            }
            k--;
        }
        return ans;
    }
};