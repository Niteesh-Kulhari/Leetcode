class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        int left = 0;
        int right = s1.length()-1;
        while(left < s2.length()){
            if(left + s1.length() <= s2.length()){
                string temp = s2.substr(left, s1.length());
                sort(temp.begin(), temp.end());

                if(s1 == temp){
                    return true;
                }
            }

            left++;
        }

        return false;
    }
};