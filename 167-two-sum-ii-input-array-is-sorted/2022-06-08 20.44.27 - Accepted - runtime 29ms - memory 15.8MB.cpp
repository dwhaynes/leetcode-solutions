class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> cache;
        for(int i = 0; i < numbers.size();i++){

            if(cache.find(target-numbers[i]) != cache.end())
                return {cache[target-numbers[i]]+1,i+1};
                
            cache[numbers[i]] = i;
            
        }
        return {};
    }
};