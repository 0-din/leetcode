class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l, m, h;
        l = 0;
        h = nums.size();
        m = (l + h) / 2;

        for(int i = 0; i < nums.size(); i++){

            if(nums[m] == target)
                return m;
            else if(target > nums[m]){
                l = m + 1;
                m = (l + h) / 2;
            }
            else if(target < nums[m]){
                h = m - 1;
                m = (l + h) / 2;
            }
        }

        return -1;
    }
};