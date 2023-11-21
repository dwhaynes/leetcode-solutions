class Solution {
public:
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copy(nums1);
        int p1 = 0, p2 = 0;
        for(int p = 0; p < n + m; p++){
            if(p2 >= n || (p1 < m && copy[p1] < nums2[p2]))
                nums1[p] = copy[p1++];
            else
                nums1[p] = nums2[p2++];
        }        
    }
};