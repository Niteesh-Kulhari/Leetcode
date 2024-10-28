class Solution {
    private:
    int binarySearch(vector<int> &nums, int start, int end, int target){
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if(n == 1){
            if(target == nums[0]){
                return 0;
            }else{
                return -1;
            }
        }

        int left = 0;
        int right = n-1;

        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(nums[mid] > nums[n-1]){
                left = mid+1;
            }else{
                right = mid - 1;
            }

        }

        int ans = binarySearch(nums, 0, left-1, target);
        if(ans != -1){
            return ans;
        }


        return binarySearch(nums, left, n-1, target);


    }
};