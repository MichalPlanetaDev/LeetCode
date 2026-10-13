class LRUCache {
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> lookup;
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = lookup.find(key);

        if (it == lookup.end())
            return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = lookup.find(key);

        if (it != lookup.end()) {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        if (cache.size() == capacity) {
            lookup.erase(cache.back().first);
            cache.pop_back();
        }

        cache.emplace_front(key, value);
        lookup[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */