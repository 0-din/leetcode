#include <string>
#include <vector>
#include <limits.h>

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

    string longestCommonPrefix_BinarySearch(vector<string>& strs) {
        if(strs.empty()) return "";
        
        int minLen = INT_MAX;

        for(const auto& str : strs){
            minLen = min(minLen, (int)str.size());
        }

        int low = 0, high = minLen;

        while (low <= high){
            int mid = (low + high) /2;
            if(allHavePrefix(strs, mid)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return strs[0].substr(0, high);        
    }
    bool allHavePrefix(const vector<string>& strs, int len){
        string prefix = strs[0].substr(0, len);
        for(const auto& str : strs){
            if(str.substr(0, len) != prefix)
                return false;
        }
    }
};