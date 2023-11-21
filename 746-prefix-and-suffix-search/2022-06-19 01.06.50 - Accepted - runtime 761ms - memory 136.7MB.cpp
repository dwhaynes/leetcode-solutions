class WordFilter {
    struct TrieNode{
        map<int,TrieNode*> children;
        int weight = 0;
    };
    TrieNode* trie;
public:
    WordFilter(vector<string>& words) {
        trie = new TrieNode;
        int wt = 0;
        for(string word: words){
            TrieNode* curr = trie;
            curr->weight = wt;
            int L = word.size();
            for(int i = 0; i < L; i++){
                TrieNode* tmp = curr;
                for(int j = i; j < L; j++){
                    int code = (word[j] - '`')*27;
                    if(!tmp->children[code]) tmp->children[code] = new TrieNode;
                    tmp = tmp->children[code];
                    tmp->weight = wt;
                }
                
                tmp = curr;
                for(int k = L-1-i; k>=0; k--){
                    int code = word[k]-'`';
                    if(!tmp->children[code]) tmp->children[code] = new TrieNode;
                    tmp=tmp->children[code];
                    tmp->weight = wt;
                }
                
                int code = (word[i]-'`')*27 + (word[L-1-i]-'`');
                if(!curr->children[code]) curr->children[code] = new TrieNode;
                curr = curr->children[code];
                curr->weight = wt;
            }
            wt++;
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* curr = trie;
        int i = 0, j=suffix.size()-1;
        while(i < prefix.size() || j >= 0){
            auto c1 = i < prefix.size() ? prefix[i]: '`';
            auto c2 = j >= 0 ? suffix[j] : '`';
            int code = (c1 - '`')*27 + (c2-'`');
            curr = curr->children[code];
            if(!curr) return -1;
            i++; j--;
        }
        return curr->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */