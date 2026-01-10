class Solution {
public:
    bool isValid(vector<int>& nums, int mid_max, int n){
        vector<long long>arr(begin(nums), end(nums));

        for( int i =0; i < n-1; i++){
            if(arr[i] > mid_max) return false;


            long long buffer = mid_max - arr[i];
            arr[i + 1] = arr[i  +1 ] - buffer; 
        }
        return arr[n-1] <= mid_max;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int leftMax =0;
        int rightMax = *max_element(begin(nums), end(nums));
        int result;

        while( leftMax <= rightMax){
            int mid_max = leftMax + ( rightMax - leftMax)/2;

            if( isValid(nums, mid_max, n)){
                result = mid_max;
                rightMax = mid_max - 1;
            }else{
                leftMax = mid_max + 1;
            }
        }
        return result;
    }
};