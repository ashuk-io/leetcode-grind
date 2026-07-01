class Solution {
public:
    double myPow(double x, long n) {
        if ( n == 0 ) return 1;
        if ( n == 1 ) return x;
        if ( x == 0 ) return 0;
        if ( x == 1 ) return 1;
        if ( x == -1 && n%2 == 0) return 1;
        if ( x == -1 && n%2 != 0) return -1;        
        if ( n < 0) {
            x = 1/x;
            n = -n;
        }
        double ans = 1;
        while ( n > 0){
            if ( n%2 == 1){
                ans = ans * x;
                n = n - 1;
            }
            else {
                x *= x;
                n /= 2;
            }
        }
        return ans;
    }
};