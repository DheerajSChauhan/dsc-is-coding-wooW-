class Solution {
public:
    int canShip(vector<int>& weights, int days, int mid){
        int currentDay =0;
        int day =1;
        for( int w : weights){
            if( currentDay + w > mid){
                day++;
                currentDay =0;
            }
            currentDay += w;
        }
        return day <= days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(begin(weights), end(weights));
        int r = accumulate(begin(weights), end(weights), 0);
        int ans = r;

        while( l <= r){
            int mid = l+(r-l)/2;

            if( canShip(weights, days, mid)){
                ans = mid;
                r = mid -1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};