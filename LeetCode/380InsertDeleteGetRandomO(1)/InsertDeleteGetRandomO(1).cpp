class RandomizedSet {

public:

    std::vector<int> arr;
    std::map<int, int> m;

    RandomizedSet() {
    }
    
    // Time:O(1), Space:O(n)
    bool insert(int val) {
        if (m.find(val) == m.end()) {
            m[val] = arr.size();
            arr.push_back(val);
            return true;
        }
        return false;
    }
    
    // Time:O(1), Space:O(n)
    bool remove(int val) {
        if (m.find(val) != m.end()) {
            arr[m[val]] = arr[arr.size() - 1];
            m[arr[arr.size() - 1]] = m[val];
            m.erase(val);
            arr.pop_back();
            return true;
        }
        return false;
    }
    
    // Time:O(1), Space:O(1)
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};
