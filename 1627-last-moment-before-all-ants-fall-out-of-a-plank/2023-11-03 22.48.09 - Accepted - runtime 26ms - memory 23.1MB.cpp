class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(auto l: left) if(l > ans) ans = l;
        for(auto r: right) if(n-r > ans) ans = n-r;
        return ans;
    }
};