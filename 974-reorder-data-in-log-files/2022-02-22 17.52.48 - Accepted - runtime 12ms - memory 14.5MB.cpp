class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,int>> let;
        vector<string> dig;
        vector<string> temp;
        auto comp = [&](pair<string,int> a, pair<string,int> b){
            string t = a.first.substr(a.second);
            string s = b.first.substr(b.second);
            if (t == s) return (a.first.substr(0,a.second) < b.first.substr(0,b.second));
            return (t < s);
        };
        for(int i = 0; i < logs.size(); i++){
            int j = 0;
            while(!isspace(logs[i][j])) j++;
            j++;
            if(isalpha(logs[i][j])) let.push_back({logs[i],j});
            else dig.push_back(logs[i]);
        }
        
        sort(let.begin(),let.end(),comp);
        for(auto p: let) temp.push_back(p.first);
        temp.insert(temp.end(),dig.begin(),dig.end());
        
        return temp;
    }
};