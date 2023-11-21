class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        int l = nums1.size();
        if(l&1){
            return nums1[l/2];
        }else{
            return double(nums1[l/2] + nums1[l/2-1])/2;
        }
    }
};