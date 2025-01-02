class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToString;
        unordered_map<string, char> stringToChar;
        vector<string> words;
        int left = 0;

        while (left < s.length()) {
            string temp = "";
            while (left < s.length() && s[left] != ' ') {
                temp += s[left];
                left++;
            }
            words.push_back(temp);
            left++; // Move past the space
        }

        if(words.size() != pattern.length()){
            return false;
        }

        for(int i=0; i<pattern.length(); i++){

            if(charToString.find(pattern[i]) != charToString.end()){
                if(charToString[pattern[i]] != words[i]){
                    return false;
                }
            }else{
                charToString[pattern[i]] = words[i];
            }

            if(stringToChar.find(words[i]) != stringToChar.end()){
                if(stringToChar[words[i]] != pattern[i]){
                    return false;
                }
            }else{
                stringToChar[words[i]] = pattern[i];
            }

        }

        return left >= s.length();
    }
};