class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        auto it1 = unique(nums1.begin(),nums1.end());
        auto it2 = unique(nums2.begin(),nums2.end());
        nums1.resize(distance(nums1.begin(),it1));
        nums2.resize(distance(nums2.begin(),it2));
        set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(res));
        return res;
    }
};