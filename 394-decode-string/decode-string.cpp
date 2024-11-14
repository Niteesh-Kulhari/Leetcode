class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ']'){
                string temp = "";

               while(st.top() != '['){
                temp += st.top();
                st.pop();
               }

                st.pop();
                int base = 1;
                int k = 0;

                while(!st.empty() && isdigit(st.top())){
                    k = k + (st.top() - '0') * base;
                    st.pop();
                    base = base * 10;
                }

                int currLen = temp.size();
                while(k != 0){
                    for(int j=currLen - 1; j>=0; j--){
                        st.push(temp[j]);
                    }
                    k--;
                }
            }else{
                st.push(s[i]);
            }
        }
        string ans;
        for (int i = st.size() - 1; i >= 0; i--) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};