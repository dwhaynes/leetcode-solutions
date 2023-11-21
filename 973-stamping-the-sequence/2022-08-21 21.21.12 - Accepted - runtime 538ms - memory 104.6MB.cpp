class Solution {
    struct Node{
        set<int> made, todo;
        Node(set<int> m, set<int> t){
            made = m;
            todo = t;
        }
    };
public:
    vector<int> movesToStamp(string stamp, string target) {
        int M = stamp.size(), N = target.size();
        queue<int> q;
        vector<bool> done(N,false);
        stack<int> ans;
        vector<Node> A;
        
        for(int i = 0; i <= N-M; i++){
            set<int> made, todo;
            for(int j = 0; j < M; j++){
                if(target[i+j] == stamp[j]) made.insert(i+j);
                else todo.insert(i+j);
            }
            A.push_back({made,todo});
            
            if(todo.empty()){
                ans.push(i);
                for(int j = i; j < i+M; j++)
                    if(!done[j]){
                        q.push(j);
                        done[j]=true;
                    }
            }
        }
        while(!q.empty()){
            int i = q.front(); q.pop();
            for(int j = max(0,i-M+1); j <= min(N-M,i); j++){
                if(A[j].todo.count(i)){
                    A[j].todo.erase(i);
                    if(A[j].todo.empty()){
                        ans.push(j);
                        for(int m: A[j].made)
                            if(!done[m]){
                                q.push(m);
                                done[m]=true;
                            }
                    }
                }
            }
        }
        
        for(bool b: done) if(!b) return {};
        vector<int> ret(ans.size(),0);
        int t = 0;
        while(!ans.empty()){
            ret[t++] = ans.top(); ans.pop();
        }
        return ret;
    }
};