class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> s;
        vector<string> ans;
        int tgt = 0;
        for(int i = 1; i <= n; i++){
            s.push(i);
            ans.push_back("Push");
            if(target[tgt] != i){
                s.pop();
                ans.push_back("Pop");
            }else tgt++;
            if(s.size() == target.size()) break;
        }
        return ans;
    }
};