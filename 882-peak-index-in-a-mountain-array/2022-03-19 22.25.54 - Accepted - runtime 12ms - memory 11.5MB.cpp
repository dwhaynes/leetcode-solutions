class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto peak = max_element(arr.begin(),arr.end());
        return distance(arr.begin(),peak);
    }
};