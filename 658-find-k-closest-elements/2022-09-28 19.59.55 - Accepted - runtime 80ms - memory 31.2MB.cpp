class Solution {
    struct cmp {
        int x;
        cmp(int x): x(x){}
        bool operator()(int a, int b){
            if(abs(x-a) == abs(x-b)) return a < b;
            return abs(x-a) < abs(x-b);
        }
    };
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        cmp c(x);
        sort(arr.begin(),arr.end(),c);
        vector<int> ans(arr.begin(),arr.begin()+k);
        sort(ans.begin(),ans.end());
        return ans;
    }
};