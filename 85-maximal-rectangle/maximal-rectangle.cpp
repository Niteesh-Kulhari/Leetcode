class Solution {
private:
    int largestArea(vector<int> &hist){
        stack<pair<int,int>> st;
        int n = hist.size();
        int ans = INT_MIN;

        for(int i=0; i<n; i++){
            int start = i;

            while(!st.empty() && st.top().second > hist[i]){
                int h = st.top().second;
                int idx = st.top().first;
                int w = i - idx;
                st.pop();
                ans = max(ans, (h * w));
                start = idx;
            }
            st.push({start, hist[i]});
        }

        while(!st.empty()){
            int h = st.top().second;
            int w = n - st.top().first;
            ans = max(ans, (h*w));
            st.pop();
        }

        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> hist(m, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int num = matrix[i][j] - '0';
                hist[j] = (num == 0) ? 0 : hist[j] + num; 
            }
            ans = max(ans, largestArea(hist));
        }

        return ans;
    }
};