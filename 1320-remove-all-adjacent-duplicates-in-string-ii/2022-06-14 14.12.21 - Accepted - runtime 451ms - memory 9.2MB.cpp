class Solution {
public:
    string removeDuplicates(string s, int k) {
        //vector<int> count(s.size());
        int N = s.size();
        int count[N];
        memset(count,0,sizeof(count));
        for(int i = 0; i < N; i++){
            if (i == 0 || s[i] != s[i-1]) count[i] = 1;
            else{
                count[i] = count[i-1] + 1;
                if(count[i] == k){
                    s.erase(i-k+1,k);
                    i = i-k;
                }
            }
        }
        return s;
    }
};