class Solution {
public:

//     bool isVowel(char ch) {
//     return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
//             ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
// }

    bool halvesAreAlike(string s) {
        int n = s.length();
        int i=0;
        int mid = n/2;
        int j=mid;
        
        int countLeft=0;
        int countRight=0;

        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');

        while(i < mid && j < n){
            // if( isVowel(s[i])) countLeft++;
            // if( isVowel(s[j])) countRight++;
            if(st.find(s[i]) != st.end()) countLeft++;
            if(st.find(s[j]) != st.end()) countRight++;
            i++;
            j++;
        }
        // if( countLeft == countRight)return true;
        // else return false;
        return countLeft == countRight;
    }
};