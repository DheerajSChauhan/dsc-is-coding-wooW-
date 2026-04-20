class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        //yaha ham number ko he index ke thra use karege

        for(int i=0; i<n; i++){
            int num = abs(nums[i]);
            int idx = num -1;

            if( nums[idx] < 0){
                ans.push_back(num);
            }else{
                nums[idx] *= -1;
            }
        }
        return ans;
    }
};