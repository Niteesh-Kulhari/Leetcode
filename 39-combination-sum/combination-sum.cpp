class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> combs;

        
        backtrack(target, candidates, combs, 0);
        return ans;
    }

    void backtrack(int remain, vector<int> &candidates,vector<int> &combs, int index){
        if(remain == 0){
            ans.push_back(combs);
            return;
        }else if(remain < 0){
            return;
        }

        for( int i=index; i<candidates.size(); ++i){
            combs.push_back(candidates[i]);
            backtrack(remain-candidates[i], candidates, combs, i);
            combs.pop_back();
        }
    }   
};