class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n = nums.size();
        vector<int> L(n);
        vector<int> R(n);
        
        L[0] = 1;
        for(int i=1; i<n; i++){
            L[i] = nums[i-1] * L[i-1];
        }

        R[n-1] = 1;

        for(int i=n-2; i>=0; i--){
            R[i] = R[i+1] * nums[i + 1];
        }

        for(int i=0; i<n; i++){
            ans[i] = L[i] * R[i];
        }
        return ans;
    }
};

