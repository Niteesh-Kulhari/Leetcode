class Solution {
private:
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    void backTrack(vector<vector<string>>& ans, vector<string>& temp, int index, string s){
        if(index >= s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<s.length(); i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                backTrack(ans, temp, i+1, s);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        backTrack(ans, temp, 0, s);

        for(auto vec: ans){
            for(auto s: vec){
                cout << s << " ";
            }
            cout << endl;
        }

        return ans;
    }
};