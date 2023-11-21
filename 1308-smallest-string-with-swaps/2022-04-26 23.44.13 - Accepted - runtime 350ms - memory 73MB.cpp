class Solution {
    static const int N = 100001;
    vector<int> adj[N];
    bool visited[N];
    void DFS(string& s, int vertex, vector<char>& characters, vector<int>& indices){
        characters.push_back(s[vertex]);
        indices.push_back(vertex);
        
        visited[vertex] = true;
        
        for(int adjacent: adj[vertex]){
            if(!visited[adjacent])
                DFS(s,adjacent,characters,indices);
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(auto edge: pairs){
            int src = edge[0];
            int dest = edge[1];
            
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        
        for(int vertex = 0; vertex < s.size(); vertex++){
            if(!visited[vertex]){
                vector<char> characters;
                vector<int> indices;
                
                DFS(s, vertex, characters, indices);
                
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());
                for(int index = 0; index < characters.size(); index++){
                    s[indices[index]] = characters[index];
                }
                    
            }
        }
        return s;
    }
};