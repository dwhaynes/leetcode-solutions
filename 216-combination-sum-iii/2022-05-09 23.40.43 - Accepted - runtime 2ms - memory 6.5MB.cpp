class Solution {
    
    vector<vector<int>> twoSum(int target,int start, int end){
        vector<vector<int>> res;
        int l = start, r = end;
        while(l < r){
            if(l + r == target) res.push_back({l++,r--});
            else if (l + r < target) l++;
            else r--;
        }
        return res;
    }
    vector<vector<int>> kSum(int target, int start, int end, int k){
        vector<vector<int>> res;
        if(start > end) return res;
        int average = target/k;
        if(start > average || average > end) return res;
        if(k == 2) return twoSum(target,start,end);
        for(int i = start; i <= end; i++){
            for(auto subset: kSum(target-i,i+1,end,k-1)){
                res.push_back({i});
                res.back().insert(res.back().end(),subset.begin(),subset.end());
            }
        }
        return res;
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        return kSum(n,1,9,k);
    }
};