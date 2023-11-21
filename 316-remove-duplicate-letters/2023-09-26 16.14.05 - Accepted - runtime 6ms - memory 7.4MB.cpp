class Solution {
public:
    string removeDuplicateLetters(string s) {
        deque<char> stack;
        set<char> seen;
        unordered_map<char,int> last_occurence;

        for(int i = 0; i < s.size(); i++) last_occurence[s[i]]=i;

        for(int i = 0; i < s.size(); i++){
            auto c = s[i];

            if(!seen.contains(c)){
                while(!stack.empty() && c < stack.back() && last_occurence[stack.back()] > i){
                    seen.erase(stack.back());
                    stack.pop_back();
                }
                seen.insert(c);
                stack.push_back(c);
            }
        }

        
        return string(stack.begin(),stack.end());

    }
};