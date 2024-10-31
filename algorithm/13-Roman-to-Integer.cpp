#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> map {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int number = 0;

        for(int i = 0; i < s.size() - 1; i++){
            
            if(map[s[i]] < map[s[i + 1]]){
                number -= map[s[i]];
            }
            else{
                number += map[s[i]];
            }
        }

        number += map[s.back()];
        return number;
    }
};