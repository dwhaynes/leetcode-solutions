class Solution {
    struct TrieNode{
        vector<TrieNode*> children = vector<TrieNode*>(26,nullptr);
        bool isWord = false;
    };
    TrieNode root, *curr;
public:
    void dfs(TrieNode* curr, string& word, vector<string>& result){
        if(result.size() == 3) return;
        if(curr->isWord) result.push_back(word);
        for(char c = 'a'; c <= 'z'; c++){
            if(curr->children[c-'a']){
                word+=c;
                dfs(curr->children[c-'a'],word,result);
                word.pop_back();
            }
        }
    }
    void insert(string& s){
        curr = &root;
        for(char c: s){
            if(!curr->children[c-'a']) curr->children[c-'a'] = new TrieNode;
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
    }
    vector<string> query(string& prefix){
        curr = &root;
        vector<string> result;
        for(char c: prefix){
            if(!curr->children[c-'a']) return result;
            curr = curr->children[c-'a'];
        }
        dfs(curr,prefix,result);
        return result;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        for(string w: products){
            insert(w);
        }
        string prefix;
        for(char c: searchWord){
            prefix+=c;
            result.push_back(query(prefix));
        }
        return result;
    }
};