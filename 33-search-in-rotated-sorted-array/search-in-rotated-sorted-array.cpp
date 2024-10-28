class Solution {
public:
    int binarySearch(vector<int> &nums, int left, int right, int target){
        while(left <=  right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] > target){
                right = mid -1;
            }else{
                left = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target){
                return 0;
            }else{
                return -1;
            }
        }
        int n = nums.size();
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] > nums[n-1]){
                left = mid + 1;
            }
            else{
                right = mid -1;
            }
        }
        
        int ans = binarySearch(nums, 0, left-1, target);

        if(ans!=-1){
            return ans;
        }
        
        return binarySearch(nums, left, n-1, target);
    }
};