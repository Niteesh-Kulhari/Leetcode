class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string ans = "";
        st.push(s[0]);

        for(int i=1; i<s.length(); i++){
            if(!st.empty() && abs(s[i] - st.top()) == 32){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};