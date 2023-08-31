class MedianFinder {
public:
    vector<int> small, large;
    int val;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // 2 heaps -> Time:O(log(n)), Space:O(n)
        small.push_back(num); push_heap(small.begin(),small.end());
        if ((small.size() != 0 && large.size() != 0 && (small[0] > -1*large[0]))
            || small.size() > large.size()+1) {
                val = small.front();
                pop_heap(small.begin(), small.end()); small.pop_back();
                large.push_back(-1*val); push_heap(large.begin(), large.end());
        }
        if (large.size() > small.size()+1) {
            val = -1*large.front();
            pop_heap(large.begin(), large.end()); large.pop_back();
            small.push_back(val); push_heap(small.begin(), small.end());
        }
    }
    
    double findMedian() {
        // Find median -> Time:O(1), Space:O(1)
        if (small.size() > large.size()) {
            return small[0];
        }
        else if (small.size() < large.size()) {
            return -1*large[0];
        }
        else {
            return (small[0] + -1*large[0]) / 2.0;
        }
    }
};
