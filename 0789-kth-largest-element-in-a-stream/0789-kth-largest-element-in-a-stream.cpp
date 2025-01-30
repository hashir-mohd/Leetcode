class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>,greater<int>> maxHeap;


    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int a:nums){
            maxHeap.push(a);
            if(maxHeap.size()>k) maxHeap.pop();
        }
    }
    
    int add(int val) {
        maxHeap.push(val);
        if(maxHeap.size() >k){
            maxHeap.pop();
        }
        return maxHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */