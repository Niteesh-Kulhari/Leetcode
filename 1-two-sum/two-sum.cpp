class Solution {
private:
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            int comp = target - nums[i];

            if(map.find(comp) != map.end()){
                ans.push_back(i);
                ans.push_back(map[comp]);
            }

            map[nums[i]] = i;
        }

        return ans;
    }
};