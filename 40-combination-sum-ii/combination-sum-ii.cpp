class Solution {
private:
    void backTrack(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& comb, int index, int remain){
        if(remain == 0){
            ans.push_back(comb);
        }else if( remain < 0){
            return;
        }

        for(int i=index; i<candidates.size(); i++){

            if(i>index && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > remain) break;
            comb.push_back(candidates[i]);
            backTrack(candidates, ans, comb, i+1, remain - candidates[i]);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, ans, comb, 0, target);

        return ans;
    }
};