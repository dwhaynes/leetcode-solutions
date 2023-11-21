class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size()-1;
        while(l <= r){
            int m = l + ((r-l) >> 1);
            if(arr[m]-m-1 < k){
                l = ++m;
            }else{
                r = --m;
            }
        }
        return l+k;
    }
};