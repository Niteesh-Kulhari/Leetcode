class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int n = nums.size();
        int left = 0, right = 0;
        int zeroCount = 0;

       for(int right = 0; right <n; right++){
            if(nums[right] == 0){
                zeroCount++;
            }

            while(zeroCount > k){
                if(nums[left] == 0){
                    zeroCount--;
                }
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
       }

        return maxLength;
    }
};