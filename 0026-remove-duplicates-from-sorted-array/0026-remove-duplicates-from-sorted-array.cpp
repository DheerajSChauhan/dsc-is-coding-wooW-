class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();
        int i = 0 ;
        for ( int j = 0 ; j < k ; j++){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};