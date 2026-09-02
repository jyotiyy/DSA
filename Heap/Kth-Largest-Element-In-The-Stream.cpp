We are asked to return the kth largest everytime so its suitable to keep only k elements in a minHap and returning the top every time 

class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> minHeap; //this is min heap syntax :  also max Heap is priority_queue<int> 
    int k;
public:
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums)add(num);
    }
    
    int add(int val) {
        if(minHeap.size() < k || minHeap.top() < val){
            minHeap.push(val); 
            if(minHeap.size()>k)minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */