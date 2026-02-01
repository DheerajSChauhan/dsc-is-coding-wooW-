class Solution {
public:
    
    double power( double x, long long n){
        //base case
        if(n == 0)return 1;

        //recursion call(aadhi power)
        double half = power(x, n/2);

        //if even n
        if( n % 2 == 0){
            return half* half;
        }else{
            ///odd n hai
            return x * half* half;
        }

    }


    double myPow(double x, int n) {
        long long N = n; //overflow

        if( N < 0){
            x = 1/x;
            N = -N;
        }
        return power(x,N);
    }
};