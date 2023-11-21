class Solution {
public:
    map<pair<int,int>,bool> memo;
    vector<int> nums;
    int possible;
    
    bool recurse(int mask, int sidesDone){
        int total = 0;
        int L = nums.size();
        
        pair<int,int> memoKey = {mask,sidesDone};
        for(int i = L-1; i >=0; i--){
            if((mask & (1<<i)) == 0) total+=nums[L-1-i];
        }
        if(total > 0 && total%possible == 0) sidesDone++;
        if(sidesDone == 3) return true;
        if(memo.find(memoKey) != memo.end()) return memo[memoKey];
        
        bool ans = false;
        int c = total/possible;
        int rem = possible*(c+1)-total;
        
        for(int i = L-1; i >= 0; i--){
            if(nums[L-1-i] <= rem && (mask & (1 << i)) > 0){
                if(recurse(mask ^ (1<<i),sidesDone)){
                    ans = true;
                    break;
                }
            }
        }
        
        memo[memoKey]=ans;
        return ans;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() == 0) return false;
        
        int L = matchsticks.size();
        int peri = accumulate(matchsticks.begin(),matchsticks.end(),0);
        possible = peri/4;
        if(peri%4) return false;
        this->nums = matchsticks;
        return recurse((1<<L)-1,0);
    }
};