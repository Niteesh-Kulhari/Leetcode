class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        unordered_map<int, vector<int>> mp2;
        vector<int> ans;

        for(auto x: nums){
            mp[x] += 1;
        }
        

        for(auto x: mp){
            mp2[x.second].push_back(x.first);
        }

        for( int i=nums.size(); i > 0 && ans.size() <k; i--){
            if(mp2.count(i)){
                for(int num : mp2[i]){
                    ans.push_back(num);

                    if(ans.size() == k){
                        return ans;
                    }
                }
            }
        }

        

        return ans;

    }
};