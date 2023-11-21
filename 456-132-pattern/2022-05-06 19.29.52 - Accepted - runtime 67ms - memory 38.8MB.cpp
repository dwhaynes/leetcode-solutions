class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        stack<int> stack;
        vector<int> mini(nums.size());
        mini[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) mini[i] = min(mini[i-1],nums[i]);
        
        for(int j = nums.size()-1; j > 0; j--){
            if(nums[j] <= mini[j]) continue;
            
            while(!stack.empty() && stack.top() <= mini[j]) stack.pop();
            
            if(!stack.empty() && stack.top() < nums[j]) return true;
            
            stack.push(nums[j]);
        }
        return false;
    }
};