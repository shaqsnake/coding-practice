// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-26 11:32:49
 * @LastEditTime: 2019-08-26 11:45:21
 * @Description: 706. Design HashMap
 */

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap(): h(vector<list<pair<int, int>>>(n)) {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int t = key % n;
        auto it = find(key);
        if (it != h[t].end()) it->second = value;
        else h[t].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int t = key % n;
        auto it = find(key);
        if (it != h[t].end()) return it->second;
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int t = key % n;
        auto it = find(key);
        if (it != h[t].end()) h[t].erase(it);
    }

private:
    int n = 10007;
    vector<list<pair<int, int>>> h;
    list<pair<int, int>>::iterator find(int key) {
        int t = key % n;
        auto it = h[t].begin();
        while (it != h[t].end()) {
            if (it->first == key) break;
            it++;
        }

        return it;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
