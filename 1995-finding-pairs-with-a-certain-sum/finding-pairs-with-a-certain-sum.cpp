class FindSumPairs {
public:
vector<int> v1,v2;
unordered_map<int, int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;

        for(int i=0; i<nums2.size(); i++){
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
        for(int num : v1){
            int toFind = tot - num;
            if(mp.find(toFind) != mp.end()){
                count += mp[toFind];
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