class Solution {
public:
    int maxScore(string s) {
        int zeroCount = 0;
        int oneCount  = 0;
        int totalOneCount = 0;

        for(char c: s){
            if(c == '1') totalOneCount++;
        }

        int ans = 0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i] == '0'){
                zeroCount++;
            }else if(s[i] == '1'){
                oneCount++;
            }
            int temp = zeroCount + (totalOneCount - oneCount);
            ans = max(ans, temp); 
        }

        return ans;

    }
};