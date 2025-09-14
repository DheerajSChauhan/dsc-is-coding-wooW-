class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int depth = 0;
        for(int i=0 ; i<s.length() ; i++){
            char c=s[i];
            if( c == '('){
                if(depth > 0) ans+=c; depth++;
            }else{
                depth--;
                if(depth> 0) ans+=c;
            }
        }
        return ans;
    }
};