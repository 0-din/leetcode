#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.size(); i++)
        {
            if(haystack[i] == needle[0] && haystack.substr(i, needle.size()) == needle)
                return i;
        }

        return -1;
    }

    //gpt solution.
    // int strStr(string haystack, string needle) {
    //     int n = haystack.size(), m = needle.size();
        
    //     for (int i = 0; i <= n - m; i++) {  // Stop loop earlier
    //         if (haystack.substr(i, m) == needle) {
    //             return i;
    //         }
    //     }

    //     return -1;
    // }
};