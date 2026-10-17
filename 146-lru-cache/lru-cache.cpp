struct Node {
    int key, val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(this), next(this) {}
    Node(int k, int v, Node* p, Node* n) : key(k), val(v), prev(p), next(n) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        dummy = new Node(-1, -1);
        tail = dummy;
    }
    
    void _to_tail(int key) {
        Node* curr = store[key];
        if (curr == tail) return;
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;

        curr->next = dummy;
        curr->prev = tail;
        tail->next = curr;
        dummy->prev = curr;

        tail = curr;
    }
    
    int get(int key) {
        if (store.find(key) != store.end()) {
            _to_tail(key);
            return store[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (store.find(key) != store.end()) {
            _to_tail(key);
            store[key]->val = value;
        } else {
            Node* node = new Node(key, value, tail, dummy);
            store[key] = node;
            tail->next = node;
            dummy->prev = node;
            tail = node;
            ++size;
        }
        if (size > capacity) {
            Node* curr = dummy->next;
            dummy->next = curr->next;
            curr->next->prev = dummy;
            store.erase(curr->key);
            delete curr;
            --size;
        }
    }

    int capacity;
    int size;
    Node* dummy;
    Node* tail;
    unordered_map<int, Node*> store;
    
};

// operations = [1, 3]
// store = {
//     1:1,
//     2:2,
//     3:3
// }
// count = {
//     1:1,
//     // 2:0,
//     3:1,
// }

/*
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
*/


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */