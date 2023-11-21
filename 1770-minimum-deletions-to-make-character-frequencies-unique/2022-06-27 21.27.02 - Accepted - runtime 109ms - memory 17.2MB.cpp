class Solution {
public:
    int minDeletions(string s) {
        vector<int> hist(26,0);
        priority_queue<int> pq;
        for(auto ch: s) hist[ch-'a']++;
        int ans = 0;
        sort(hist.begin(),hist.end(),greater<int>());
        int maxFreq = s.size();
        for(int i = 0; i < 26; i++){
            if(hist[i] > maxFreq){
                ans+=hist[i]-maxFreq;
                hist[i]=maxFreq;
            }
            maxFreq = max(0,hist[i]-1);
        }
        return ans;
        
        
    }
};