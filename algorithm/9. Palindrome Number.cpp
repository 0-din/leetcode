#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x % 10 == 0){
            return false;
        }

        int r = 0;
        while(x > r){
            r = (r * 10) + (x % 10);
            x /= 10;
        }

        return x == r || x == r / 10;
    }

    bool isPalindrome_WithStringMethod(int x) {
        std::string strnumber = std::to_string(x);

        for(int i = 0; i < strnumber.size(); i++){
            if(strnumber[i] != strnumber[strnumber.size() - i -1]){
                return false;
            }
        }

        return true;
    }

    bool isPalindrome_WithStringMethod_WithPointer(int x) {
        std::string strnumber = std::to_string(x);
        int left = 0;
        int right = strnumber.size() - 1;

        for(int i = 0; i < strnumber.size() / 2; i++){
            if(strnumber[left] != strnumber[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};