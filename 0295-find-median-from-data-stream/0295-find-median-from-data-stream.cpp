class MedianFinder {
public:
    priority_queue<int>low;
    priority_queue<int,vector<int>,greater<int>>up;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(low.empty() || num <= low.top()){
            low.push(num);
        }
        else{
            up.push(num);
        }
        if(low.size() > up.size()+ 1){
            up.push(low.top());
            low.pop();
        }
        else if(low.size() < up.size()){
            low.push(up.top());
            up.pop();
        }
    }
    
    double findMedian() {
        if(low.size() > up.size()){
            return low.top();
        }
        else  return double((low.top()+ up.top())/2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */