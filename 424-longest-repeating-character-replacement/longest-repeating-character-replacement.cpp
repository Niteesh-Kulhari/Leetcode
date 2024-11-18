class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        int ans = 0;
        int left = 0;

        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            maxFreq = max(maxFreq, mp[s[i]]);
            int window = i - left + 1;

            if(window - maxFreq > k){
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};