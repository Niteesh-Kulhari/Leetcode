class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<int, string>>> mp;
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end() ){
            return "";
        }

        int lo = 0;
        int hi = mp[key].size()-1;

        while( lo <= hi){
            int mid  = lo + (hi-lo)/2;

            if(mp[key][mid].first < timestamp){
                lo = mid+1;
            }else if(mp[key][mid].first > timestamp){
                hi = mid - 1; 
            }else{
                return mp[key][mid].second;
            }
        }

        if(hi >= 0){
            return mp[key][hi].second;
        }

        return "";


    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */