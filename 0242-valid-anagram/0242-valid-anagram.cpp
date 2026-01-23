class Solution {
public:
    bool isAnagram(string s, string t) {
        int n= s.size();
        int m= t.size();
        if(n != m) return false;
        sort(begin(s), end(s));
        sort(begin(t), end(t));
        
        return s == t;
    }
};