class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     unordered_map<int,int> numsMap;
     vector<vector<int>> res;
     sort(nums.begin(), nums.end());
     int n = nums.size();

    for(int i=0; i<n; i++){
        numsMap[nums[i]] = i;
    }

    for(int i=0; i<n; i++){
        if(nums[i] > 0){
            break;
        }

        for(int j=i+1; j<n; j++){
            int val = -1 * (nums[i] + nums[j]);
            if(numsMap.find(val) != numsMap.end() && numsMap[val] > j){
                res.push_back({nums[i], nums[j], val});
            }
            //because the array is sorted this will skip directly to last index of the same element
            j = numsMap.find(nums[j])->second;
        }
        i = numsMap.find(nums[i])->second;
       
    }

    return res;
    }
};


