class Solution {
private:
    string phoneDigits;
    vector<string> ans;
    //vector<string> comb = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    unordered_map<char, string> comb = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {ans};
        }
        phoneDigits = digits;
        backTrack(0, "");

        return ans;

    }

    void backTrack(int index, string path){
        if(path.length() == phoneDigits.length()){
            ans.push_back(path);
        }
        
        string chars = comb[phoneDigits[index]];
        for(auto ch: chars){
            path.push_back(ch);
            backTrack(index+1, path);
            path.pop_back();
        }
    }
};