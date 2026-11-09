// class LRUCache {
// public:
//     int capacity;
//     queue<pair<int,int>> que;

//     LRUCache(int capacity) {
//         this->capacity = capacity;
//     }

//     int get(int key) {

//         int n = que.size();
//         int ans = -1;

//         for(int i = 0; i < n; i++) {

//             auto p = que.front();
//             que.pop();

//             if(p.first == key) {
//                 ans = p.second;
//             }
//             else {
//                 que.push(p);
//             }
//         }

//         if(ans != -1) {
//             que.push({key, ans});
//         }

//         return ans;
//     }

//     void put(int key, int value) {

//         int n = que.size();

//         for(int i = 0; i < n; i++) {

//             auto p = que.front();
//             que.pop();

//             if(p.first != key) {
//                 que.push(p);
//             }
//         }

//         if(que.size() >= capacity) {
//             que.pop();
//         }

//         que.push({key, value});
//     }
// };


class LRUCache {
public:

    int capacity;

    list<pair<int,int>> ls;

    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        if(mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];

        int value = it->second;

        // Remove from old position
        ls.erase(it);

        // Move to front
        ls.push_front({key, value});

        // Update iterator
        mp[key] = ls.begin();

        return value;
    }

    void put(int key, int value) {

        // If key already exists
        if(mp.find(key) != mp.end()) {

            ls.erase(mp[key]);
        }

        // Insert at front
        ls.push_front({key, value});

        mp[key] = ls.begin();

        // If capacity exceeded
        if(ls.size() > capacity) {

            int oldKey = ls.back().first;

            mp.erase(oldKey);

            ls.pop_back();
        }
    }
};