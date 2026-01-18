class Solution {
public:
    string orderlyQueue(string s, int k) {
        //simply sort kar lenge agar k>1
        if(k > 1){
            sort(begin(s), end(s));
            return s;
        }
        //agar k =1 hai toh hame brute force he karna padega 
        string result=s;
        int n=s.length();
        for(int i=1; i <= n-1; i++){
            string temp = s.substr(i) + s.substr(0,i);
            result = min(result, temp);
        }
        return result;
    }
};