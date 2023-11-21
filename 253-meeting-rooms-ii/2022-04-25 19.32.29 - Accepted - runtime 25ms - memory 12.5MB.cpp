class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        vector<int> start, end;
        for(auto i: intervals){
            start.push_back(i[0]);
            end.push_back(i[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int sp = 0, ep = 0, rooms = 0;
        
        while(sp < intervals.size()){
            if(start[sp] >= end[ep]){
                ep++;
                rooms--;
            }
            rooms++;
            sp++;
        }
        return rooms;
    }
};