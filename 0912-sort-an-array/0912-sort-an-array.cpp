class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int , vector<int>, greater<int>>minh(begin(nums), end(nums));
        int i=0;
        while(!minh.empty()){
            nums[i] = minh.top();
            minh.pop();
            i++;
        }
        return nums;
    }
};