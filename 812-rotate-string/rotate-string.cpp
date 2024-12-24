class Solution {
public:
    bool rotateString(string s, string goal) {
        int size = s.length();

        for(int i=0; i<size; i++){
            if(s == goal){
                return true;
            }

            char front = s[0];      // Get the first character
            s.erase(s.begin());     // Remove the first character
            s += front;   
        }

        return false;
    }
};