#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;

        for(auto i = digits.rbegin(); i != digits.rend(); ++i)
        {
            int t = *i + c;
            *i = t % 10;
            c = t / 10;

            if(c == 0) break;
        }

        if(c == 1)
            digits.insert(digits.begin(), c);
            
        return digits;
    }
};