#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int mid = (nums.size() - 1) / 2;
        int left = 0, right = 0;

        
        
    }

    //GPT solution
    // int gpt_findMiddleIndex(vector<int>& nums) {
    //     int totalSum = 0;
    //     for(int num : nums) totalSum += nums[num];

    //     int leftSum = 0;
    //     for(int i = 0; i < nums.size(); i++)
    //     {
    //         int rightSum = totalSum - leftSum - nums[i];

    //         if(leftSum == rightSum) return i;

    //         leftSum += nums[i];
    //     }
    // }
};