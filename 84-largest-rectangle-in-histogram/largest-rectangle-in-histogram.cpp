class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = INT_MIN;
        stack<pair<int,int>> st;
        int n = heights.size();

        for(int i=0; i<n; i++){
            int start = i;
            while( !st.empty() &&  st.top().second > heights[i]){
                int height = st.top().second;
                int index = st.top().first;
                int width = i - index;
                ans = max(ans, (width * height));
                cout<< ans << endl;
                st.pop();
                start = index;
            }
            st.push({start, heights[i]});
        }
        while (!st.empty()) {
            int width = heights.size() - st.top().first;
            int height = st.top().second;
            st.pop();
            
            ans = max(ans, height * width);
        }
        return ans;
    }
};