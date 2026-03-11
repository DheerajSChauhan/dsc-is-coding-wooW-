class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //brute force apporoach
        vector<int>ans;

        //nums1 ke har element ke liye
        for(int i=0; i<nums1.size(); i++){
            int element = nums1[i];
            int index = -1;
            //nums2 me element ke position find karo
            for( int j=0; j< nums2.size(); j++){
                if(nums2[j] == element){
                    index = j;
                    break;
                }
            }
            int nextGreater = -1;
            //nums2 ke right side me next greater element find karo
            for( int i=index+1; i<nums2.size(); i++){
                if(element < nums2[i]){
                    nextGreater = nums2[i];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
    }
};