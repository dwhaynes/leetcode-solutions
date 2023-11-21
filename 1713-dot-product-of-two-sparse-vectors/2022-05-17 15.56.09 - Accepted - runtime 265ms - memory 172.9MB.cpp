class SparseVector {
    
public:
    vector<int> nums;
    SparseVector(vector<int> &nums) {
        this->nums = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += (nums[i]*vec.nums[i]);
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);