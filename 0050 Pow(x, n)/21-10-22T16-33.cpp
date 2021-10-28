class Solution {
public:
    double pow(double x, long long n){
        if(n == 1){
            return x;
        }
        double foo = pow(x, n/2);
        if(n % 2 == 1){
            return foo * foo * x;
        }else{
            return foo * foo;
        }
    }
    
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        bool neg = false;
        long long _n = n;
        if(n < 0){
            neg = true;
            _n = -1 * _n;
        }
        double p = pow(x, _n);
        return neg? 1 / p : p;
    }
};