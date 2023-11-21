class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        for(auto op: ops){
            if(op == "+"){
                int n = score.size();
                score.push_back(score[n-1] + score[n-2]);
            }else if(op == "D"){
                score.push_back(score.back() * 2);
            }else if(op == "C"){
                score.pop_back();
            }else score.push_back(stoi(op));
        }
        return accumulate(score.begin(),score.end(),0);
    }
};