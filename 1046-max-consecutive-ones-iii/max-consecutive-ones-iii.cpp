class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int n = nums.size();
        int left = 0, right = 0;
        int zeroCount = 0;

        while( right < n){
            if(nums[right] == 0){
                zeroCount++;
            }

            while(zeroCount > k){
                if(nums[left] == 0){
                    zeroCount--;
                }
                left++;
            }

            right++;

            maxLength = max(maxLength, right - left);
        }

        return maxLength;
    }
};