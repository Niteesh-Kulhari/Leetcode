class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int ans = INT_MIN;
        int n = heights.size();

        for(int i=0; i<n; i++){
            int start = i;

            while(!st.empty() && st.top().second > heights[i]){
                int h = st.top().second;
                int idx = st.top().first;
                int w = i - idx;
                ans = max(ans, (h*w));
                st.pop();
                start = idx;
            }
            st.push({start, heights[i]});
        }

        while(!st.empty()){
            int h = st.top().second;
            int w = n - st.top().first;
            ans = max(ans, (h*w));
            st.pop();
        }

        return ans;
    }
};