class SegmentTree{
    public:
    int n;
    vector<int> tree;
    SegmentTree(vector<int> &nums){
        n = nums.size();
        tree.resize(4*n);
        buildTree(0,0,n-1,nums);
    }
    void buildTree(int i,int l,int r,vector<int> &nums){
        if(l == r){
            tree[i] = nums[l];
            return;
        }
        int m = (l+r)/2;
        buildTree(2*i+1,l,m,nums);
        buildTree(2*i+2,m+1,r,nums);
        tree[i] = tree[2*i+1]+tree[2*i+2];
    }
    int sumrange(int start,int end,int l,int r,int i){
        if(start > r || end < l){
            return 0;
        }
        if(l>= start && r <= end){
            return tree[i];
        }
        int m = (l+r)/2;
        return sumrange(start,end,l,m,2*i+1)+sumrange(start,end,m+1,r,2*i+2);
    }
    void update(int idx,int val,int i,int l,int r){
        if(l == r){
            tree[i] = val;
            return;
        }
        int m =(l+r)/2;
        if(m >= idx){
            update(idx,val,2*i+1,l,m);
        }else{
            update(idx,val,2*i+2,m+1,r);
        }
        tree[i] = tree[2*i+1]+tree[2*i+2];
    }

};
class NumArray {
   SegmentTree* sgmnt;
public:
    NumArray(vector<int>& nums) {
        sgmnt = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        sgmnt->update(index,val,0,0,sgmnt->n-1);
    }
    
    int sumRange(int left, int right) {
        return sgmnt->sumrange(left,right,0,sgmnt->n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */