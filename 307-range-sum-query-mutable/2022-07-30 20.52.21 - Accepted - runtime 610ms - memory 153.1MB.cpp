class NumArray {
    vector<int> nums;
    vector<int> tree;
    int n;
    void build(int index,int l, int r){
        if(l == r) tree[index]=nums[l];
        if(l < r){
            int mid = (l+r)/2;
            build(index*2+1,l,mid);
            build(index*2+2,mid+1,r);
            tree[index] = tree[index*2+1] + tree[index*2+2]; 
        }
        
    }
    int query(int index, int lo, int hi, int l, int r){
        if(hi < l || lo > r) return 0;
        if(lo >= l && hi <= r) return tree[index];
        int mid = (lo+hi)/2;
        int left = query(index*2+1,lo,mid,l,r);
        int right = query(index*2+2,mid+1,hi,l,r);
        return left+right;
    }
    void update(int index, int lo, int hi, int pos,int val){
        if(lo == hi){
            tree[index] = val;
            return;
        }
        int mid = (lo+hi)/2;
        if(pos <= mid) update(index*2+1,lo,mid,pos,val);
        else update(index*2+2,mid+1,hi,pos,val);
        tree[index] = tree[index*2+1] + tree[index*2+2];
    }
public:
    NumArray(vector<int>& nums) {
        if(nums.size() > 0){
           n = nums.size();
            this->nums = nums;
            tree = vector<int>(4*n,0);
        }
        build(0,0,n-1);
    }
    
    void update(int index, int val) {
        return update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */