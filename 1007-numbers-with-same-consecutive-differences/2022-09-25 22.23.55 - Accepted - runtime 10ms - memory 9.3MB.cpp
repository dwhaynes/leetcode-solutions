class Solution {
    void dfs(int n, int num, int k, vector<int>& results){
        if(n == 0){
            results.push_back(num);
            return;
        }
        vector<int> next;
        
        int tail = num %10;
        next.push_back(tail+k);
        if(k != 0) next.push_back(tail-k);
        for(auto digit: next){
            if(0 <= digit && digit < 10){
                int newNum = num * 10 + digit;
                dfs(n-1,newNum,k,results);
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n == 1){
            vector<int> ans(10);
            iota(ans.begin(),ans.end(),0);
            return ans;
        }
        
        vector<int> results;
        
        for(int i = 1; i < 10; i++)
            dfs(n-1,i,k,results);
        
        return results;
    }
};