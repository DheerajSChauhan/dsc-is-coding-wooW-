class Solution {
public:
    int findPivot(vector<int>& nums){ //minimum index nikal lenge
        int n= nums.size();
        int l=0;
        int h=n-1;

        while( l<h){
            int mid = l+(h-l)/2;
            if(nums[mid] < nums[h]){
                h = mid;
            }else{
                l= mid+1;
            }
        }
        return l;
    }

    int binarySearch(int l,int h, vector<int>& nums, int target){
        int idx =-1;
        while(l <= h){
            int mid = l+(h-l)/2;
            if(nums[mid] == target){
                idx = mid;
                break;
            }else if( nums[mid] < target){
                l = mid+1;
            }else{
                h = mid -1;
            }
        }
        return idx;
    }


    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivotIndex = findPivot(nums);

        //left side binary search 
        int idx = binarySearch(0, pivotIndex -1, nums, target);
        if( idx != -1){
            return idx;
        }
        //nahi toh right side binary search karo
         idx = binarySearch(pivotIndex, n-1, nums, target);
        return idx;
    }
};