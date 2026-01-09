class Solution {
public:
    bool canEatAll(vector<int>& piles, int mid, int h){
        int actualHours = 0;
        for(int x : piles){
            actualHours = actualHours + x/mid; //hours nikal jayega

            if( x%mid != 0){
                actualHours++;
            }
        }
        return actualHours <= h;
    }



    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        while( l < r){
            int mid= l+(r-l)/2;

            if( canEatAll(piles, mid, h)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};