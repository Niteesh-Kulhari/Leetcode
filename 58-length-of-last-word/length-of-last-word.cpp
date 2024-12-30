class Solution {
public:
    int lengthOfLastWord(string s) {
        int left = 0;
        int ans = 0;
        int count = 0;
        while(left < s.length()){
            if(s[left] == ' '){
                while(s[left] == ' '){
                    left++;
                }
                ans = count;
                count = 0;
                continue;
            }

            count++;
            left++;
        }

        if(count > 0) ans = count;

        return ans;
    }
};