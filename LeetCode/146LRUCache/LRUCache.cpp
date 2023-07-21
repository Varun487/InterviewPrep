struct Node {
    int key, val;
    Node *prev, *next;
    Node(int key, int val) : val(val), key(key), prev(NULL), next(NULL) {}
};

class LRUCache {
public:

    map<int,Node*> cache;
    Node *left = new Node(0,0), *right = new Node(0,0);
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        left->next = right;
        right->prev = left;
    }

    void remove(Node *n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void insert(Node *n) {
        n->next = right;
        n->prev = right->prev;
        right->prev = n;
        n->prev->next = n;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node *n = new Node(key, value);
        cache[key] = n;
        insert(cache[key]);
        if (cache.size() > cap) {
            Node *lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};
