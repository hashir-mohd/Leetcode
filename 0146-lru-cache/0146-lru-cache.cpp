class LRUCache {
    int capacity;
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end())return -1;
        auto it= cache[key];
        int value= it->second;
        dll.erase(it);
        dll.push_front({key,value});
        cache[key]=dll.begin();
        return value;

    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end()){
            auto it= cache[key];
            dll.erase(it);
        }
        else if(dll.size()==capacity){
            auto it= dll.back();
            cache.erase(it.first);
            dll.pop_back();
        }

        dll.push_front({key,value});
        cache[key]=dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */