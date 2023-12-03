class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int count = 0;
        int n = points.size();  
        for(int i=1;i<n;i++){
            int x1 = points[i-1][0] , x2 = points[i][0];
            int y1 = points[i-1][1] , y2 = points[i][1];
            int xDiff = abs(x2-x1);
            int yDiff = abs(y2-y1);
            count += max(xDiff,yDiff);
        }
        return count;
    }
};