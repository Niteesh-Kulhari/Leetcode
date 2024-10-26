class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i=0; i<tokens.size(); i++){
            if( tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(stoi(tokens[i]));
            }else{
            int number1 = st.top();
            st.pop();
            int number2 = st.top();
            st.pop();  

            int temp = 0;
            switch(tokens[i][0]){
                case '+':
                    temp = number1 + number2;
                    st.push(temp);
                    break;
                case '-':
                    temp = number2 - number1;
                    st.push(temp);
                    break;
                case '*':
                    temp = number1 * number2;
                    st.push(temp);
                    break;
                case '/':
                    if(number1 != 0){
                        temp = number2 / number1;
                    }else{
                        temp = 0;
                    }
                    st.push(temp);
                    break;
                    }
            }


            
        }

        return st.top();
    }
};