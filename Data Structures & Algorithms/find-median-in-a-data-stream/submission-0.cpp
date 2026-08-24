class MedianFinder {
private:
    priority_queue<int> maxHeapLeft;
    priority_queue<int, vector<int>, greater<int>> minHeapRight;
    int n;

public:
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        if(n==0){
            maxHeapLeft.push(num);
            n++;
            return;
        }

        if(maxHeapLeft.top()>num){
            maxHeapLeft.push(num);
        }
        else{
            minHeapRight.push(num);
        }
        n++;

        while((int)maxHeapLeft.size() - (int)minHeapRight.size() > 1){
            int ele = maxHeapLeft.top();
            maxHeapLeft.pop();
            minHeapRight.push(ele);
        }
        while((int)minHeapRight.size() - (int)maxHeapLeft.size() > 1){
            int ele = minHeapRight.top();
            minHeapRight.pop();
            maxHeapLeft.push(ele);
        }
    }
    
    double findMedian() {
        if(n%2){
            if(minHeapRight.size()>maxHeapLeft.size()){
                return minHeapRight.top();
            }
            else{
                return maxHeapLeft.top();
            }
        }
        else{
            int a = minHeapRight.top();
            int b = maxHeapLeft.top();
            return ((a+b)*1.0)/2.0;
        }
    }
};
