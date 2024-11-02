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
        if(mp.find(v2[index]) != mp.end()){
            mp[v2[index]]--;
        }
        v2[index] += val;
        if(mp.find(v2[index]) != mp.end()){
            mp[v2[index]]++;
        }else{
            mp[v2[index]] = 1;
        }
    }
    
    int count(int tot) {
        int count = 0;
        for(int num : v1){
            int toFind = tot - num;
            if(toFind >= 0 && mp.find(toFind) != mp.end() && mp[toFind] > 0){
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