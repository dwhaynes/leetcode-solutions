class Solution {
    vector<int> split(string s){
        vector<int> out;
        while(!s.empty()){
            auto p = s.find(".");
            //if (p == string::npos) break;
            string pos = s.substr(0,p);
            out.push_back(stoi(pos));
            if (p == string::npos) break;
            s.erase(0,p+1);
        }
        return out;
    }
public:
    int compareVersion(string version1, string version2) {
        auto v1 = split(version1);
        auto v2 = split(version2);
        int sz1 = v1.size(), sz2 = v2.size();
        int i = 0, j = 0;
        while(i < sz1 || j < sz2){
            int n1 = (i < sz1) ? v1[i] : 0;
            int n2 = (j < sz2) ? v2[j] : 0;
            if(n1 != n2){
                return (n1 < n2) ? -1 : 1;
            }
            if (i < sz1) i++;
            if (j < sz2) j++;
        }
        return 0;
    }
};