class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> base = {0,1};
        if(n == 0) return base;
        for(int i = 1; i < n; i++){
            for(int j = base.size()-1; j >= 0; j--){
                base.push_back(base[j]| (1 << i));
            }
        }
        return base;
    }
};