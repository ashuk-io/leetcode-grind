class Solution {
public:
    bool isPalindrome(int x) {
        long long revInt = 0;
        if ( x<0) return false;
        int temp = x;
        while ( temp > 0){
            int digit = temp % 10;
            revInt = (revInt * 10) + digit;
            temp/=10;
        
        }
        return revInt == x;
    }
};