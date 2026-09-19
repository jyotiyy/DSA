class NumArray {
private:
    vector<int> a;
public:
    NumArray(vector<int>& nums) {
        a= vector<int>(nums.begin(),nums.end());
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++) sum+= a[i];

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */