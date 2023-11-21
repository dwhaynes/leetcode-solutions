class Solution {
    struct cmp{
        bool operator()(pair<int,string>& a, pair<int,string>& b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> freq;
        for(auto word: words) freq[word]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto& [w,f]: freq) pq.push({f,w});
        vector<string> ans;
        while(!pq.empty() && k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};