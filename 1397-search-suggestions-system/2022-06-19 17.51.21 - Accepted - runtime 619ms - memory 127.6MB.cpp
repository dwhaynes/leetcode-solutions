class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        map<string,vector<string>> tree;
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        for(auto prod: products){
            for(int i = 1; i <= prod.size(); i++){
                tree[prod.substr(0,i)].push_back(prod);
            }
        }
        for(int i = 1; i <= searchWord.size();i++){
            auto words = tree[searchWord.substr(0,i)];
            
            while(words.size() > 3) words.pop_back();
            ans.push_back(words);
        }
        return ans;
    }
};