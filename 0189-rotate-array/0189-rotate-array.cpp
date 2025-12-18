class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        while( start < end){
            swap( nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k == 0) return;
        k = k%n;
        //step1:reverse whole array
        reverse(nums, 0, n-1);
        //step2:reverse till k-1
        reverse(nums, 0, k-1);
        //step3:reverse from k-1 to n-1
        reverse(nums, k, n-1);

    }
};