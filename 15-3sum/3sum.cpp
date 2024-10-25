class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int left, right;


        for(int i=0; i<nums.size(); i++){
            if( i>0 && nums[i] == nums[i-1]){
                continue;
            }

            left = i + 1;
            right = nums.size() - 1;

            while( left < right ){
                int threeSum = nums[i] + nums[left] + nums[right];
                
                if( threeSum > 0 ){
                    right --;
                }else if(threeSum < 0 ){
                    left ++;
                }else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    right--;
                    left++;

                    while( left < right && nums[left] == nums[left-1] ) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
            }
        }

        return ans;

    }
};


