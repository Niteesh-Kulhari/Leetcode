class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n);

        for( int i=0; i<n; i++){
            int currDay = i;
            int currTemp = temperatures[i];

            while(!st.empty() && currTemp > st.top().second){
                int prevDay = st.top().first;
                int prevTemp = st.top().second;
                st.pop();
                ans[prevDay] = currDay - prevDay;
            }

            st.push({currDay, currTemp});
        }

        return ans;
    }
};