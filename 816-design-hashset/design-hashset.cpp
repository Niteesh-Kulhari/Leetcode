class MyHashSet {
    unordered_map<int, bool> hashSet;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        hashSet[key] = true;
    }
    
    void remove(int key) {
        hashSet.erase(key);
    }
    
    bool contains(int key) {
        return hashSet.find(key) != hashSet.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */