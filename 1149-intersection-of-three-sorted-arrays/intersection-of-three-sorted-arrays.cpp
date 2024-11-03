class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        unordered_map<int, int> mp;

        for(int num: arr1){
            mp[num]++;
        }

        for(int num: arr2){
            mp[num]++;
        }

        for(int num: arr3){
            mp[num]++;
        }

        for(auto num: mp){
            if(num.second == 3){
                ans.push_back(num.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};