class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();
        int totalSum = (n * (n + 1)) / 2;
        int arraySum = 0;
        for(int i = 0; i < nums.size(); i++) {
            arraySum += nums[i];
        }
        return totalSum - arraySum;
    }
};
