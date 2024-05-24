class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string, char> mp2;
        vector<string> words;

        stringstream ss(s);

        string word;

        while(ss >> word){
            words.push_back(word);
        }

        if (pattern.length() != words.size()) {
            return false;
        }

        for(int i = 0; i < pattern.size(); i++){
            if( mp.count(pattern[i]) && mp[pattern[i]] != words[i] ){
                return false;
            }

            if( mp2.count(words[i]) && mp2[words[i]] != pattern[i]){
                return false;
            }

            mp[pattern[i]] = words[i];
            mp2[words[i]] = pattern[i];
        }

        // for(int i=0; i<words.size(); i++){
        //     cout << words[i] << " ";
        // }



        return true;
    }
};