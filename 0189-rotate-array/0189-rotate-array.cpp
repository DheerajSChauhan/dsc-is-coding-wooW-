class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 0) return;
        k = k % size;
        vector<int> temp(size);
        for(int i = 0; i < size; i++){
            temp[(i + k) % size] = nums[i];
        }
        
        
        nums = temp;
    }
};
