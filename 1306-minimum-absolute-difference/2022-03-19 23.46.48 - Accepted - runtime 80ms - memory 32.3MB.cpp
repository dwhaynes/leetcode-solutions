class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int mindiff = INT_MAX;
        for(int i = 1; i < arr.size(); i++){
            int diff = arr[i]-arr[i-1];
            if (diff == mindiff) res.push_back({arr[i-1],arr[i]});
            else if (mindiff > diff){
                mindiff = diff;
                res = {{arr[i-1],arr[i]}};
            }
        }
        return res;
    }
};