class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int A = (ax2-ax1)*(ay2-ay1);
        int B = (bx2-bx1)*(by2-by1);

        int left = max(ax1,bx1);
        int right = min(ax2,bx2);
        int xOverlap = (right-left);

        int top = max(ay1,by1);
        int bottom = min(ay2,by2);
        int yOverlap = (bottom-top);

        int overlap = 0;
        if(xOverlap > 0 && yOverlap > 0) overlap = xOverlap * yOverlap;

        return A + B - overlap;
    }
};