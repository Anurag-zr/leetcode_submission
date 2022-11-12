class MedianFinder {
public:
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        
        if(maxHeap.size()>minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        // cout<<maxHeap.top()<<" "<<minHeap.top()<<endl;
    }
    
    double findMedian() {
        
        if(maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top())/2.0;
        
        return minHeap.top();
    }
    
private:
    priority_queue<int,vector<int>> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */