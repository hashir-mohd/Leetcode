class MedianFinder {
public:
std::multiset<int> ms;
    std::multiset<int>::iterator mid;
        MedianFinder() : mid(ms.end()) {}

    
    void addNum(int x) {
        ms.insert(x);

        if (ms.size() == 1) {
            mid = ms.begin();
            return;
        }

        // Move median iterator appropriately
        if (ms.size() % 2 == 1) { // Odd size
            if (x >= *mid)
                ++mid;
        } else { // Even size
            if (x < *mid)
                --mid;
        }
    }
    
    double findMedian() {
        if (ms.empty()) return -1;
        if (ms.size() % 2 == 1) return *mid; // Odd case
        return (*mid + *std::next(mid)) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */