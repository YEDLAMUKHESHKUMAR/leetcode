class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xPoints;
        int n = points.size();
        for(int i=0;i<n;i++){                    // :)
            xPoints.push_back(points[i][0]);
        }
        sort(xPoints.begin(),xPoints.end());
        int maxArea = INT_MIN;
        for(int i=1;i<xPoints.size();i++){
            maxArea = max(maxArea , xPoints[i] - xPoints[i-1]);
        }
        return maxArea;
    }
};