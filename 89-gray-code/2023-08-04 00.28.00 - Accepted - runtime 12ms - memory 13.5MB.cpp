class Solution {
    vector<int> ans = {0,1};
public:
    vector<int> grayCode(int n) {
        if(n == 1) return ans;
        stack<int> stack;
        for(int depth  = 1; depth < n; depth++){
            for(auto bits: ans){
                stack.push(bits);
            }
            while(!stack.empty()){
                auto temp = stack.top();
                ans.push_back(temp | (1 << depth));
                stack.pop();
            }
        }
        return ans;
    }
};