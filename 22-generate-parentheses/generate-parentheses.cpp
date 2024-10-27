class Solution {
private:
    void solve(vector<string> &ans, string &str, int openC, int closeC, int n){
        if( openC == n && closeC == n){
            ans.push_back(str);
            return;
        }

        if( openC < n){
            str += "(";
            solve(ans, str, openC+1, closeC, n);
            str.pop_back();
        }

        if( closeC < openC){
            str += ")";
            solve(ans, str, openC, closeC+1, n);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> ans;

        solve(ans, str, 0, 0, n);

        return ans;
    }
};