class Solution {
public:
    bool isAlphaNum(char ch){
        if ( ('0' <= ch && ch <= '9') ||
        ('a' <= tolower(ch) && tolower(ch) <= 'z'))
        {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int start = 0 , end = s.size()-1;
        while(start <= end){
            if (!isAlphaNum(s[start])){
                start++;
                continue;
            }
            if (!isAlphaNum(s[end])){
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])) return false;
            start++; end--;
        }
        return true;
    }
};