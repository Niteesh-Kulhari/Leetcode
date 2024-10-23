class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int longestStreak = 1;
        int currentStreak = 1;

        for(int i=1; i<n; i++){
            
            if(nums[i] != nums[i-1]){
                if( nums[i] == nums[i-1] + 1){
                currentStreak++;
                //cout << currentStreak << " ";
            }else{
                if(currentStreak >= longestStreak ) {
                    longestStreak = currentStreak;
                }
                currentStreak = 1;
            }
            }
                
        }

        

        return max(longestStreak, currentStreak);      
    }
};