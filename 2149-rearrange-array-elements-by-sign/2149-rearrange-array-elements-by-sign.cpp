class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pi = 0;
        int ni = 1;
        vector<int>result(n);

        for( int x : nums){
            if( x > 0){
                result[pi] = x;
                pi+=2;
            }else{
                result[ni] = x;
                ni+=2;
            }
        }
        return result;
    }
};