class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;
        if(k == 0){
            return;
        }

        vector<int> temp(n);

        int i=0;
        int j = n-k;
        while(i<n && j<n){
            temp[i] = nums[j];
            i++;
            j++;
        }
        int start = 0;
        while( i<n && start < j){
            temp[i] = nums[start];
            i++;
            start++;
        }

        for(int i=0; i<n; i++){
            nums[i] = temp[i];
        }
    }
};