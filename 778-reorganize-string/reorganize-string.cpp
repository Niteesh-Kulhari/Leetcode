class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for(char ch: s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> max_heap;

        for( auto [ch, freq]: mp){
            max_heap.push({freq, ch});
        }

        string ans;

        while(max_heap.size() >= 2){
            auto [freq1, char1] = max_heap.top();
            max_heap.pop();
            auto[freq2, char2] = max_heap.top();
            max_heap.pop();

            ans += char1;
            ans += char2;

            if(--freq1 > 0) max_heap.push({freq1, char1});
            if(--freq2 > 0) max_heap.push({freq2, char2});
        }

        if(!max_heap.empty()){
            auto[ freq, ch ] = max_heap.top();
            max_heap.pop();
            if(freq > 1) return "";
            ans += ch;
        }

        return ans;

    }
};