class Solution {
public:
    int minDeletions(string s) {
        vector<int> hist(26,0);
        priority_queue<int> pq;
        for(auto ch: s) hist[ch-'a']++;
        for(auto value: hist) if(value > 0) pq.push(value);
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