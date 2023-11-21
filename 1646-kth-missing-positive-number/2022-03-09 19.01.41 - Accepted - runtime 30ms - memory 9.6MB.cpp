class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ct = 0;
        for(int i = 1; i < arr.back()+k; i++){
            if(find(arr.begin(),arr.end(),i) == arr.end()) ct++;
            if(ct == k) return i;
        }
        return arr.back()+k;
    }
};