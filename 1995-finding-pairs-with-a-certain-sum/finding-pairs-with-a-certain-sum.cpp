class FindSumPairs {
public:
    vector<int> v1;
    vector<int> v2;
    unordered_map<int, int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;

        for(int i=0; i<v2.size(); i++){
            mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp[v2[index]]--;
        if(mp[v2[index]] == 0) mp.erase(v2[index]);
        v2[index] += val;
        mp[v2[index]]++;

    }
    
    int count(int tot) {
        int count = 0;

        for(int i=0; i<v1.size(); i++){
            int num = tot - v1[i];
            if(mp.find(num) != mp.end()){
                count += mp[num];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */