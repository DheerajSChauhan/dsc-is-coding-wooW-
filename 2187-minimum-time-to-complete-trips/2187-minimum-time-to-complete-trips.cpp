// class Solution {
// public:

//     int possibleHai(vector<int>& time, int mid_time, int totalTrips){
//         long long actualTime = 0;

//         for( int &x : time){
//             actualTime = actualTime + mid_time/x; //number of trips har bus ke
//         }
//         return actualTime >= totalTrips;
//     }


//     long long minimumTime(vector<int>& time, int totalTrips) {
//         int n = time.size();
//         long long l = 0;
//         long long r = (long long)*min_element(begin(time), end(time))* totalTrips;

//         while( l<r){
//             long long mid_time = l+(r-l)/2;
//             if(possibleHai(time, mid_time, totalTrips)){
//                 r = mid_time;
//             }else{
//                 l = mid_time + 1;
//             }
//         }
//         return l;
//     }
// };

class Solution {
public:
    bool possibleHai(vector<int>& time, long long mid_time, long long totalTrips) {
        long long actualTrips = 0;

        for (int x : time) {
            actualTrips += mid_time / x;   // trips for each bus
            if (actualTrips >= totalTrips) // early stop to avoid overflow
                return true;
        }
        return actualTrips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;  // minimum possible time
        long long r = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        while (l < r) {
            long long mid_time = l + (r - l) / 2;
            if (possibleHai(time, mid_time, totalTrips)) {
                r = mid_time;
            } else {
                l = mid_time + 1;
            }
        }
        return l;
    }
};
