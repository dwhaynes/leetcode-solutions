class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return decodeString(s,index);
    }
    string decodeString(const string& s, int& index){
        string result;
        while(index < s.size() && s[index] !=']'){
            if(!isdigit(s[index])) result+=s[index++];
            else{
                int k = 0;
                while(index < s.size() && isdigit(s[index]))
                    k = k*10+s[index++]-'0';
                index++;
                string decodedString = decodeString(s,index);
                index++;
                while(k-- > 0) result+=decodedString;
            }
        }
        return result;
    }
};