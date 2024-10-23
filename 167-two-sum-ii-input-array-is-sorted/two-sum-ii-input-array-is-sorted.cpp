class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;

        for(int i=0; i<numbers.size(); i++){
            mp[numbers[i]] = i;
        }

        for(int i=0; i<numbers.size(); i++){
            if(mp.find(target-numbers[i]) != mp.end()){
                return{i+1, mp[target-numbers[i]]+1};
            }
        }

        return {0,0};
    }
};