class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        vector<int> last = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(last[1] >= intervals[i][0]) last[1] = max(last[1], intervals[i][1]);
            else {
                res.push_back(last);
                last = intervals[i];
            }
        }
        res.push_back(last);
        return res;
    }
};