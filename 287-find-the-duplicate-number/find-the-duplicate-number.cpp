class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, -1);
        int ans = 0;

        for(int i=0; i<n; i++){
            if(vis[nums[i]] != -1){
                ans = nums[i];
                break;
            }
            vis[nums[i]] = 0;
        }

        return ans;
    }
};