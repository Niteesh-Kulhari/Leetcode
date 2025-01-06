class Solution {
private:
    int find(vector<int>& nums, int target){
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= target) count++;
        }

        return count;
    }
public:
    int specialArray(vector<int>& nums) {
        int start = 0;
        int end = nums.size();

        while(start <= end){
            int mid = start + (end-start)/2;
            int greater = find(nums, mid);

            if(greater == mid){
                return mid;
            }else if(greater > mid){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        return -1;
    }
};