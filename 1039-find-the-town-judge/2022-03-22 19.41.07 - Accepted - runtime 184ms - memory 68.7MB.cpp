class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //vector<int> trusts(n+1,0), trusted(n+1,0);
        int trusts[n+1];
        int trusted[n+1];
        memset(trusts,0,sizeof(trusts));
        memset(trusted,0,sizeof(trusted));
        for(auto t: trust){
            trusts[t[0]]++;
            trusted[t[1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(trusts[i] == 0 && trusted[i]==n-1) return i;
        }
        return -1;
    }
};