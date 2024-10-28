#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        std::vector<int> answer;

        std::unordered_map<int, int> map;
        for(int i = 0; i< nums.size(); i++){
            map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            if(map.find(target - nums[i]) != map.end() && map[target - nums[i]] != i){
                answer.push_back(i);
                answer.push_back(map[target - nums[i]]);
                break;
            }
        }

        return answer;
    }
};