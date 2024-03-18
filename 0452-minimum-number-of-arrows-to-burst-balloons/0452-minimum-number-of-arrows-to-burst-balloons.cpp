class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // ,[1,10],[3,9],[4,11],[6,7],[6,9],[8,12],[9,12],
        int n = points.size();
        sort(points.begin(),points.end());
        int mini = points[0][1];
        int count = 1 ;
        for(int i = 1;i<n;i++){
            if(points[i][0] > mini){
                mini = points[i][1];
                count++;
            }
            if(points[i][1] < mini){
                mini = points[i][1];
            }
        }
        return count;
    }
};