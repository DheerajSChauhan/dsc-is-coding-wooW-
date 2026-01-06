class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l=0, r=n-1;

        while(l<r){
            int mid=l+(r-l)/2;

            if(nums[mid]> nums[r]){ //gadbad hogaye but ans to right side he hoga
                l=mid+1;
            }else{
                r = mid; // ans mid be ho sakta hai but loop mein fash sakta hai +1 nahi kar rahe hai isleya upper l<r kara rahe hai not l<=r
            }
        }
        return nums[r];
    }
};