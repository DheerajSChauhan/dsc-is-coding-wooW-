class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        long long ans = 0;
        //1. whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }


        //2. signedness
        if( i<n && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1:1;
            i++;
        }

        //3. conversion
        while( i<n && isdigit(s[i])){
            ans = ans*10 + (s[i] - '0');
        
            //CHECK OVERFLOW    
            if( sign == 1 && ans > INT_MAX ){
                return INT_MAX;
            }
            if(  sign == -1 && -ans < INT_MIN ){
                return INT_MIN;
            }
            i++;
        }

        return sign*ans;

    }
};