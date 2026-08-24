class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int maxSize;
   public:
    KthLargest(int k, vector<int>& nums) {
        maxSize = k;
        for (auto a : nums) {
            if (minHeap.size() < k) {
                minHeap.push(a);
            } else {
                if (minHeap.top() < a) {
                    minHeap.pop();
                    minHeap.push(a);
                }
            }
        }
    }

    int add(int val) {
        if (minHeap.size() < maxSize) {
            minHeap.push(val);
        } 
        else {
            if (minHeap.top() < val) {
                minHeap.pop();
                minHeap.push(val);
            }
        }
        return minHeap.top();
    }
};
