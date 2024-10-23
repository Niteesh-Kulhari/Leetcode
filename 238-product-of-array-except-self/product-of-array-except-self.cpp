class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n = nums.size();
        
        
        ans[0] = 1;
        for(int i=1; i<n; i++){
            ans[i] = nums[i-1] * ans[i-1];
        }
        int r = 1;

        for(int i=n-1; i>=0; i--){
            ans[i] = ans[i] * r;
            r = nums[i] * r;
        }

        return ans;
    }
};

