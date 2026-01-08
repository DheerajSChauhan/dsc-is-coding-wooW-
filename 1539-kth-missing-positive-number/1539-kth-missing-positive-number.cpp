class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l=0, r=n-1;
        int mid =-1;

        while( l<=r){
            mid = l+(r-l)/2;
            int kitneMissingElementTillEnd = arr[mid] -(mid +1);

            if( kitneMissingElementTillEnd < k){
                l = mid +1;
            }else{
                r = mid -1;
            }
        }
        return l +k;
    }
};