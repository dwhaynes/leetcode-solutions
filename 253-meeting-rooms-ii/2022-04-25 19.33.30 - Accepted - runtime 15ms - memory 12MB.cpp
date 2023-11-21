class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        vector<int> start, end;
        for(int i = 0; i < intervals.size(); i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
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