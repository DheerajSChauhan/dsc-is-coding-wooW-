class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        //brute force aproach : using XOR operation.
        // int ans= 0;
        // int n = nums.size(); 

        // using for each loop:

        // for( int x: nums){
        //     ans = ans ^ x;
        // }

        // using for loop:
        // for( int i = 0 ;i<n; i++){
        //     ans = ans^nums[i];
        // }
        //return ans;


        //optimal apporach : using Binaray Search:
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while( l < h){
            int mid = l + (h - l)/2;

            //rightside even hai ya odd nikal lo
            bool isEven;
            if((h - mid)%2 ==0){
                isEven = true;
            }else{
                isEven = false;
            }

            //check karo bagal wala element equall hai ya nahi
            if( nums[mid] == nums[mid + 1]){
                if(isEven){ // for even
                    l = mid+2;
                }else{ // for odd
                    h= mid-1;
                }
            }else{ // nums[mid] != nums[mid+1]
                if( isEven){
                    h= mid;
                }else{ // for odd
                    l = mid+1;
                }
            }
        }
        return nums[h];
    }

};