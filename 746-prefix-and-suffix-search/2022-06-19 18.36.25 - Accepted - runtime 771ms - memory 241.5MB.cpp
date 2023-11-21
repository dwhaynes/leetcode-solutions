class WordFilter {
    struct TrieNode{
        array<unique_ptr<TrieNode>,27> children;
        int weight = 0;
    };
    TrieNode trie;
public:
    void insert(string word, int pos){
        auto node = &trie;
        for(auto ch: word){
            int c = ch - 'a';
            if(node->children[c]) node = node->children[c].get();
            else node->children[c].reset(node = new TrieNode());
            node->weight = pos;
        }
    }
    int query(string word){
        auto node = &trie;
        for(auto ch: word){
            int c = ch - 'a';
            if(node->children[c]) node = node->children[c].get();
            else return -1;
        }
        return node->weight;
    }
    WordFilter(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            auto word = words[i];
            int n = word.size();
            for(int j = 1; j <= n; j++){
                auto key = word.substr(n-j,j);
                key+='{'+word;
                insert(key,i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return query(suffix + '{' + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */