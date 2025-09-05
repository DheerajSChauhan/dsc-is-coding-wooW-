class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0 , l = 0 , maxCount = 0 , freq = 0, ans = 0 ;
        unordered_map<char , int>str;
        while(r < s.size()){
            str[s[r]]++;
            maxCount = max ( maxCount , str[s[r]]);
            if((r - l + 1) - maxCount > k){
                str[s[l]]--;
                l++;
            }
            ans = max(ans , r-l+1);
            r++;
        }
        return ans;
    }
};