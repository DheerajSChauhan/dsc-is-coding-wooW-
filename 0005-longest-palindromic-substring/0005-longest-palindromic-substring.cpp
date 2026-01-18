class Solution {
public:
    string expand(string s, int left, int right){
        while(left>=0 && right<= s.length() && s[left]==s[right]){
            right++;
            left--;
        }
        return s.substr(left+1, right-left-1);
    }

    string longestPalindrome(string s) {
        string ans ="";

        //har character ko center mann kar check karenge
        for(int i=0; i<s.length(); i++){
            //odd length
            string p1 = expand(s, i, i);
            //even length
            string p2 = expand(s, i, i+1);

            if( p1.length() > ans.length()) ans = p1;
            if( p2.length() > ans.length()) ans = p2;

        }
        return ans;
    }
};