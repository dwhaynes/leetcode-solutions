class Solution {
public:
    int minDeletions(string s) {
        map<char,int> hist;
        priority_queue<int> pq;
        for(auto ch: s) hist[ch]++;
        for(auto [key,value]: hist) pq.push(value);
        int ans = 0;
        while(pq.size() > 1){
            int curr = pq.top();
            pq.pop();
            if(curr == pq.top()){
                if(curr - 1 > 0) pq.push(curr-1);
                ans++;
            }
        }
        return ans;
        
        
    }
};