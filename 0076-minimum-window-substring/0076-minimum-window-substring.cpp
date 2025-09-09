class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char c : t) mp[c]++;
        int required = mp.size();
        int formed = 0;
        unordered_map<char, int> window;

        int l = 0, r = 0, minLen = INT_MAX, start = 0;

        while(r < s.size()) {
            window[s[r]]++;
            if(mp.count(s[r]) && window[s[r]] == mp[s[r]]) {
                formed++;
            }

            while(formed == required) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                window[s[l]]--;
                if(mp.count(s[l]) && window[s[l]] < mp[s[l]]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};