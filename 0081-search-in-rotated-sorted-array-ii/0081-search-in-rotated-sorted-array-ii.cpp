class Solution {
public:
    int findPivot(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        while (l < h) {
            while (l < h && nums[l] == nums[l + 1])l++;
            while (l < h && nums[h] == nums[h-1])h--;

            int mid = l + (h - l) / 2;
            if (nums[mid] > nums[h]) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return h;
    }

    int binarySearch(int l, int h, vector<int>& nums, int target) {
        while (l <= h) {
            int mid = l+(h-l)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return -1;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        // minimum index nikal lenge firr 2 sorted array mil jayega
        int pivotIndex = findPivot(nums);

        // left sorted array mein search kar lege
        int idx = binarySearch(0, pivotIndex - 1, nums, target);
        if (idx != -1) {
            return true;
        }
        // left nahi mila toh right side check karo
        idx = binarySearch(pivotIndex, n - 1, nums, target);
        return idx != -1;
    }
};