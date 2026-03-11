class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
        1. Traverse from right to left
        2. mantain the stack of grater element
        3. pop all the smaller element 
        4. stack top = next greater element
        5.store in map;
        */

        stack<int>st; //stack to maintain the decreasing order
        unordered_map<int, int>mp; //map->element->next greater element;
        //nums2 me right to left traverse kar lete hai
        for(int i=nums2.size()-1; i>=0; i--){
            int curr = nums2[i];
            while(!st.empty() && st.top() <= curr){
                st.pop();
            }
            //if stack empty ho gaya to -1 map me dal do
            if( st.empty()){
                mp[curr] = -1;
            }else{
                //agar ye hai toh ye next greater eement he hoga
                mp[curr] = st.top();
            }
            //push it to the stack
            st.push(curr);
        }
        vector<int>ans;
        //nums1 ke answers map se fetch karo
        for( int i= 0; i<nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};