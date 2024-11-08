class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.size() == 0){
            return word2;
        }else if(word2.size() == 0){
            return word1;
        }

        int left = 0, right = 0;
        string ans = "";
        while(left < word1.size() && right < word2.size()){
            ans += word1[left];
            left ++;
            ans += word2[right];
            right ++;
        }

        while( left < word1.size()){
            ans += word1[left];
            left++;        
        }

        
        while( right < word2.size()){
            ans += word2[right];
            right++;        
        }

        return ans;
    }
};