class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
      vector<float> line;

      for(int i = 0; i < dist.size(); i++){
          line.push_back((float)dist[i]/speed[i]);
      }
      sort(line.begin(),line.end());
      int ans = 0;
      for(int i = 0; i < line.size(); i++){
          if(line[i] <= i) break;
          ans++;
      }
      return ans;  
    }
};