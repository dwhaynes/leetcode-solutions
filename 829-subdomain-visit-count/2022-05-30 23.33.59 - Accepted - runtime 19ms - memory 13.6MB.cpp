class Solution {
    pair<int,vector<string>> split(string& s){
        int count = 0;
        int it = 0;
        vector<string> subdomains;
        
        while(it < s.size() && isdigit(s[it])){
            count*=10;
            count+=s[it]-'0';
            it++;
        }
        it++;
        subdomains.push_back(s.substr(it));
        while(it < s.size()){
            while(it < s.size() && s[it] != '.') it++;
            if(it < s.size()){
                it++;
                subdomains.push_back(s.substr(it));
            }
        }
        return {count,subdomains};
    }
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int> counts;
        vector<string> out;
        for(auto cpdomain: cpdomains){
            auto [count, domains] = split(cpdomain);
            for(auto domain: domains) counts[domain]+=count;
        }
        for(auto [key,value]: counts){
            out.push_back(to_string(value)+' '+key);
        }
        return out;
    }
};