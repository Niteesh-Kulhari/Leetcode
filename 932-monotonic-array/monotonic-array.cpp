class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int left = 1;
        int size = nums.size();
        bool isIncreasing = true;
        bool isDecreasing = true;

        while(left < size){
            if(nums[left] < nums[left-1]){
                isIncreasing = false;
            }else if(nums[left] > nums[left - 1]){
                isDecreasing = false;
            }
            left++;
        }

        return isIncreasing || isDecreasing;
    }
};