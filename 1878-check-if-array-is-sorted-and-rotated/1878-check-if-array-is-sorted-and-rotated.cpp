class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int peak=0;
        for(int i = 0; i < size ; i++){
            if(nums[i] > nums[(i+1)%size]){
                peak++;
            }
        }
        if(peak >1){
            return false;
        }
        return true;
    }
};