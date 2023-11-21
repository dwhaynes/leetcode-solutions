class Solution {
    unordered_map<char,int> map;
public:
    int romanToInt(string s) {
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        
        int sum = 0;
        int current = map[s[0]];
        for(int i=1; i < s.size(); i++){
            if(map[s[i]] > current){
                current*= -1;
            }
            sum+=current;
            current = map[s[i]];
        }
        sum+=current;
        return sum;
    }
};