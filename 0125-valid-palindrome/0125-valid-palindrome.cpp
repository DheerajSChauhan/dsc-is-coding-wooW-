// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0 ;
//         int right = s.size() - 1 ;

//         while(left < right){
//             if(!isalnum(s[left])){
//                 left++;
//             }else if(!isalnum(s[right])){
//                 right--;
//             }else if(tolower(s[left])!= tolower(s[right])){
//                 return false;
//             }else{
//                 left++;
//                 right--;
//             }
//         }
//         return true ;
//     }
// };
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0 ;
        int end = s.length() -1;
        while(start < end){
            while( (start < end) && !isalnum(s[start])) start++;
            while( (start < end) && !isalnum(s[end])) end--;
            if(tolower(s[start]) != tolower(s[end])) return false;
            start++;
            end--;
        }
        return true;
    }
};