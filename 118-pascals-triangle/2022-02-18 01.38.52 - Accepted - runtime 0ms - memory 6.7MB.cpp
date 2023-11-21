class Solution {
    map<pair<int,int>,int> memo;
    int coeff(int n, int c){
        if(n == c || c == 0 || n == 0) return 1;
        if(c == 1) return n;
        if(memo.find({n,c}) != memo.end()) return memo[{n,c}];
        memo[{n,c}] = coeff(n-1, c) + coeff(n-1, c-1);
        memo[{n,n-c}] = memo[{n,c}];
        return memo[{n,c}];
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int n = 0; n < numRows; n++){
            vector<int> temp;
            for(int c = 0; c <= n; c++){
                temp.push_back(coeff(n,c));
            }
            result.push_back(temp);
        }
        return result;
    }
};