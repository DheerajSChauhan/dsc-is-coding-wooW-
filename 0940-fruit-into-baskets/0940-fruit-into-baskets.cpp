class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0 , r = 0 , maxLen = 0 , k =2;
        map<int , int>mpp;
        while(r < fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size() > k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size() <= k){
                maxLen = max( maxLen , r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};