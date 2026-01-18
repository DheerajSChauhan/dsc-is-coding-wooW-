class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="";
        string s2="";
        for(auto &p : word1){
            s1 += p;
        }
        for(auto &p : word2){
            s2 += p;
        }
        return s1 == s2;
    }
};