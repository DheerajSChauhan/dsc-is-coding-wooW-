// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         // if(s.size() != goal.size()) return false;
//         // //s k os k sath jod, fir usme goal find kar
//         // // auto temp = s + s;
//         // // return temp.find(goal) != string::npos; 
//         // if((s+s).find(goal) != string::npos)return true;
//         // return false;
//         int n = s.size();
//         int g = goal.size();
//         if( n != g ) return false;

//         string doubled = s + s;

//         if(doubled.find(goal) >= 0)return true;
//         else return false;
//     }
// };
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(); 
        int g = goal.size();

        if( n != g ) return false;

        string doubled = s + s;
        int idx = doubled.find(goal);
        return idx != -1;
        //if( idx!= -1)return true;
        //else return false;
    }
};
