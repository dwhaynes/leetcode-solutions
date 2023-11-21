class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxElement = *max_element(arr.begin(),arr.end());
        queue<int> q;
        for(auto a: arr) q.push(a);
        q.pop();

        int curr = arr[0];
        int winstreak = 0;

        while(!q.empty()){
            int op = q.front();
            q.pop();
            if(curr > op){
                q.push(op);
                winstreak++;
            }else{
                q.push(curr);
                curr = op;
                winstreak = 1;
            }
            if(winstreak == k || curr == maxElement) return curr;
        }
        return -1;
    }
};