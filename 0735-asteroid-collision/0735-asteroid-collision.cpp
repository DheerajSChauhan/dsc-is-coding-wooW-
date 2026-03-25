class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int &a : asteroids){
            //when will collision happens?
            while(!st.empty() && a < 0 && st.top() > 0){
                int sum = a + st.top();
                if( sum < 0){
                    st.pop();
                }else if( sum > 0){
                    a = 0;
                }else{
                    st.pop();
                    a=0;
                }
            }
            if( a != 0){
                st.push(a);
            }
        }
        int s = st.size();
        vector<int>result(s);
        int n = s-1;
        while(!st.empty()){
            result[n] = st.top();
            st.pop();
            n--;
        }
        return result;
    }
};