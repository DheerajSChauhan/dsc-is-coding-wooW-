class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(); // total chars ka sizze
        int index = 0;  //ye  pointer batata hai compressed array me kaha likhna hai
        int i =0;  // traverse karne k leye pointer

        //duplicate   count karte hai
        while( i < n){
            char curr_char = chars[i];
            int count = 0;
            while( i < n && curr_char == chars[i]){
                count++;
                i++;
            }
            //assign kar lete hai char ko pehele
            chars[index] = curr_char;
            index++;

            //number ko assign kar lete hai aub
            if( count > 1){
                string cnt = to_string(count);
                for( char c: cnt){
                    chars[index] = c;
                    index++;
                }
            }
        }
        return index;

    }
};