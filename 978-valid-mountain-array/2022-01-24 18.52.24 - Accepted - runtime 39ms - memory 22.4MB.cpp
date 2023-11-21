class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int upCount = 0;
        int downCount = 0;
        int index = 1;
        int n = arr.size();
        while(index < n && arr[index] > arr[index-1]){
            upCount++;
            index++;
        }
        while(index < n && arr[index] < arr[index-1]){
            downCount++;
            index++;
        }
        if(upCount && downCount){
            return (upCount + downCount == n-1);
        }
        return false;
    }
};