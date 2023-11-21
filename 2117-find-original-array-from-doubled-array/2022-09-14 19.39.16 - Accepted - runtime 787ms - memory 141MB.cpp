class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2) return {};
        
        sort(changed.begin(),changed.end());
        unordered_map<int,int> freq;
        for(auto num: changed) freq[num]++;
        
        vector<int> original;
        for(int num: changed){
            if(freq[num]){
                freq[num]--;
                int twice = 2*num;
                if(freq[twice]){
                    freq[twice]--;
                    original.push_back(num);
                }else return {};
            }
        }
        return original;
    }
};