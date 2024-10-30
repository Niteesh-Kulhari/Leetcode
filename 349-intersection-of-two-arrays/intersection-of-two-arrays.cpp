class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int> mp;
        vector<int> ans;

       for(int num : nums1){
        mp[num]++;
       }

       for( int num: nums2){
        if(mp.count(num) && mp[num] > 0){
            ans.push_back(num);
            mp[num] = 0;
        }
       }

       return ans;
    }
};