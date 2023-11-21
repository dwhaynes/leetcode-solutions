class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        int i;
        for(i = 1; i < n; i++){
            if (arr[i] <= arr[i-1]) break;
        }
        if (i == n || i == 1) return false;
        for(; i < n; i++){
            if (arr[i] >= arr[i-1]) return false;
        }
        return true;
        
    }
};