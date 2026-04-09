class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());
        //using two pointer
        int l = 0, r = 0, i = 0;
        int n= s.length();
        while( i < n){
            while(i<n && s[i] == ' '){
                i++;
            }
            while( i<n && s[i] != ' '){
                s[r++] = s[i++]; 
            }
            if(l<r){
                reverse(s.begin()+l, s.begin()+r);
                s[r++] = ' ';
                l=r;
            }
        }
        return s.substr(0, r-1);
    }
};