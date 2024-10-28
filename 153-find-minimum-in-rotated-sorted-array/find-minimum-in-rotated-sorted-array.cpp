class Solution {
public:
    int findMin(vector<int>& nums) {


        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i] < nums[i-1]){
                return nums[i];
            }
        }

        return nums[0];
    }
};