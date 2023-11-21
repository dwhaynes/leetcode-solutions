class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1){
            string ans = s;
            for(int i = 0; i < s.size(); i++){
                auto temp = s.substr(i) + s.substr(0,i);
                ans = temp < ans ? temp : ans;
            }
            return ans;
        }else{
            sort(s.begin(),s.end());
            return s;
        }
    }
};