class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size(), -1);

        int right = arr.size() - 1;
        int n = arr.size() - 1;
        int greatest = -1;
        while(right >= 0){
            ans[n] = greatest;
            greatest = max(arr[right], greatest);
            n--;
            right--;
        }

        return ans;
    }
};