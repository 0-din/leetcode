class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        long num, rev = 0;
        num = x;
        
        while(x > 0)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        
        return num == rev;
        
    }
};