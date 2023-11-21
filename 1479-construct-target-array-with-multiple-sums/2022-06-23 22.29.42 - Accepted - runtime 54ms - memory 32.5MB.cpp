class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) return target[0] == 1;
        long totalSum = accumulate(target.begin(),target.end(),0ll);
        priority_queue<long> pq;
        for(auto t: target) pq.push(long(t));
        while(!pq.empty() && pq.top() > 1){
            long largest = pq.top(); pq.pop();
            long rest = totalSum - largest;
            if (rest == 1) return true;
            long x = largest % rest;
            if(x == 0 || x == largest) return false;
            pq.push(x);
            totalSum-=(largest-x);
        }
        return true;
    }
};