#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;

        for(int i = s.size() - 1; i > -1; i--)
        {
            if(s[i] == ' ' && c == 0) continue;
            if(s[i] == ' ' && c > 0) break;
            c++;
        }

        return c;
    }
};