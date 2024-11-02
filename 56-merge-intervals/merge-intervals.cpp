class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for(int i=0; i<intervals.size(); i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }else{
                vector<int> temp = ans.back();
                if(temp[1] >= intervals[i][0] ){
                    ans.pop_back();
                    temp[1] = temp[1] >= intervals[i][1] ? temp[1] : intervals[i][1];
                    ans.push_back(temp);
                }else{
                    ans.push_back(intervals[i]);
                }
                

            }

            
        }

        return ans;
        
    }
};