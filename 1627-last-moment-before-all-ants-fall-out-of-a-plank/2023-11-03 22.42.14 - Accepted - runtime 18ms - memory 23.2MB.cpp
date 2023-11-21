class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        left.push_back(0);
        right.push_back(n);
        int l = *max_element(left.begin(),left.end());
        int r = *min_element(right.begin(),right.end());
        return max(l,n-r);
    }
};