class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans= "";
        int i = n-1;

        while( i >= 0){ //right to left move kar rahe hai (reverse string chaiye)
            //step 1: extra spaces ko hatta do
            while( i>=0 && s[i] == ' ') i--;
            //step 2: check kar lo kahhe string poora space toh nahi
            if( i<0)break; //agar poore string space hai toh break kar do

            //step 3: word k last index mark karo
            int j=i;
            //step:5; word ka start doodho
            while( i >=0 && s[i] != ' ') i--;
            //step 5: agar aub sapce aaya matlab word k beech space ko add karo
            if( !ans.empty()) ans += ' ';
            //step 6: word extrac karo
            ans += s.substr(i+1, j-i); 
        }
        return ans;
    }
};