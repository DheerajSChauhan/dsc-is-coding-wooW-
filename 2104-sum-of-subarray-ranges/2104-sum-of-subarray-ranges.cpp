class Solution {
public:
    //sub array ranges = sum of maximum subarray - sum of minimum subarray
    //sum of minimum subarray
    //next smaller left
    vector<int>NSL(vector<int>& nums, int n){
        stack<int>st;
        vector<int>result(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    } 
    //next smaller right
    vector<int>NSR(vector<int>& nums, int n){
        stack<int>st;
        vector<int>result(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    } 
    //sum of maximum subarray
    //next larger left
    vector<int>NLL(vector<int>& nums, int n){
        stack<int>st;
        vector<int>result(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    } 
    //next larger right
    vector<int>NLR(vector<int>& nums, int n){
        stack<int>st;
        vector<int>result(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    } 

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        //sum of minimum
        vector<int>left_small = NSL(nums, n);
        vector<int>right_small = NSR(nums, n);
        //sum of maximum
        vector<int>left_large = NLL(nums, n);
        vector<int>right_large = NLR(nums, n);

        long long sumMinimum = 0;
        long long sumMaximum = 0;

        for(int i=0; i<n; i++){
            //sumMinimum
            long long ls = i - left_small[i];
            long long rs = right_small[i] - i;

            //sumMaximum
            long long ll = i - left_large[i];
            long long rl = right_large[i] - i;

            sumMinimum += (long long)nums[i]*ls*rs;  
            sumMaximum += (long long)nums[i]*ll*rl;

        }    
        return sumMaximum - sumMinimum;
    }
};