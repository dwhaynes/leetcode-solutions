class Solution {
public:
    string reformatDate(string date) {
        string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int i = 0;
        string day = "", month = "", year = "";
        while(isdigit(date[i])){
            day+= date[i];
            i++;
        }
        i+=3;
        string m = date.substr(i,3);
        string* p = find(months,months + 12,m);
        month+= to_string(distance(months,p) + 1);
        i+=4;
        year = date.substr(i,4);
        stringstream ss;
        ss << year << "-";
        ss << setw(2) << setfill('0') << month << "-";
        ss << setw(2) << setfill('0') << day;
        return ss.str();
    }
};