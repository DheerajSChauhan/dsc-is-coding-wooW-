class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        sort(begin(temp), end(temp));
        //sort hogaya hai aub mujhe aub 2 array hai mere pass aub mujhe map karna padega sort array ko rankde dunga
        unordered_map<int, int>mp;
        int rank = 1;
        for(int i=0; i<arr.size(); i++){
            if( mp.find(temp[i]) == mp.end()){
                mp[temp[i]] = rank;
                rank++;
            }
        }
        //abhe tak sorrated array ko rank de deya hai aub mujhe rank ko array se reaplace kar sunga toh ans mil ayeaga
        for( int i=0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};