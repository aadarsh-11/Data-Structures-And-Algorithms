class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        if(maxh.size() < minh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size() > minh.size())
        {
            return maxh.top();
        }
        return (double)(minh.top() + maxh.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */