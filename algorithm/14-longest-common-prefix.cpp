#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        prefix = strs[0];

        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            for(; j < prefix.size(); j++){
                if(prefix[j] != strs[i][j])
                    break;
            }
            
            prefix = prefix.substr(0, j);

            if(prefix == "")
                break;
        }

        return prefix;        
    }
};