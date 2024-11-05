class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto ch: tasks){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> max_heap;

        for(auto [ch, freq] : mp){
            max_heap.push({freq,ch});
        }
        int time = 0;
        
        while(!max_heap.empty()){
            int k = n + 1;
            vector<pair<int,char>> temp;
            while(k > 0 && !max_heap.empty()){
                auto[freq, ch] = max_heap.top();
                max_heap.pop();
                freq--;
                temp.push_back({freq,ch});
                k--;
                time++;
            }
            for(auto [freq, ch] : temp){
                if(freq > 0) max_heap.push({freq, ch});
            }

            if( !max_heap.empty()){
                time += k;
            }

        }

        return time;
    }
};