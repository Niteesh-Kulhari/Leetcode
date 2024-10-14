class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        // Sorting Method than comparing

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // for (int i=0; i<s.length(); i++){
        //     if(s[i] != t[i]){
        //         return false;
        //     }
        // }


        // return true;


        // Unordered map way

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for(int i=0; i<s.length(); i++){
            sMap[s[i]]++;
            tMap[t[i]]++;
        }

        for(int i=0; i<sMap.size(); i++){
            if(sMap[i] != tMap[i]){
                return false;
            }
        }

        return true;
    }
};