class TimeMap {
public:
    map<string,vector<pair<string,int>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // Map of maps -> Time:O(1), Space:O(1)
        if (m.find(key) == m.end()) {
            vector<pair<string,int>> tempVec;
            m[key] = tempVec;
        }
        pair<string,int> tempPair(value,timestamp);
        m[key].push_back(tempPair);
    }
    
    string get(string key, int timestamp) {
        // Binary Search -> Time:O(log(n)), Space:O(1) n:values.size()
        string ans = "";
        if (m.find(key) == m.end()) {
            return ans;
        }
        vector<pair<string,int>> values = m[key];
        int mid, start = 0, end = values.size()-1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (values[mid].second == timestamp) {
                return values[mid].first;
            }
            else if (values[mid].second < timestamp) {
                ans = values[mid].first;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
