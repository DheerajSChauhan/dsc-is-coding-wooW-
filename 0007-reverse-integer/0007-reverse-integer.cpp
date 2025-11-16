class Solution {
public:
    int reverse(int x) {
        int rev = 0 ;
        while( x!= 0){
            int digits = x % 10;
            // Check if appending digit causes overflow
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && digits > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && digits < -8)) return 0;
            rev = rev * 10 + digits;
            x = x/10;
        }
        return rev;
    }
};