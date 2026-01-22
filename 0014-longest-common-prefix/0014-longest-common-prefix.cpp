class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        //1. check if string is empty or not
        if( strs.size() == 0)return "";
        //take first one as common to find common prefix for other
        string prefix = strs[0];
        for( int i =1; i<n; i++){
            while( strs[i].find(prefix) != 0){
                prefix.pop_back();
                if(prefix.empty())return "";
            }
        }
        return prefix;
    }
};
//prefix hamesa starting se hota hai 
// ek string ko refernce banao
//Uske character ko baaki sab se match karao 