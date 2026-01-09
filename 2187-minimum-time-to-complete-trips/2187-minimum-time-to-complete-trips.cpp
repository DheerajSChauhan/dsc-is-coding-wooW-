class Solution {
public:

    bool possibleHai(vector<int>& time, long long givenTime, int totalTrips){
        long long actualTime = 0;

        for(int t : time){
            actualTime = actualTime + givenTime/t;
            if (actualTime >= totalTrips) return true;  // early stop
        }

        return actualTime >= totalTrips;
    }


    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        long long l = 1;
        long long r = (long long) *min_element(begin(time), end(time))* totalTrips; //minimum element ko total time kitna lagega trip karne mein

        while(l < r){
            long long mid_time = l + (r-l)/2;

            if(possibleHai(time, mid_time, totalTrips)){
                r = mid_time;
            }else{
                l = mid_time +1;
            }
        }
        return l;
    }
};