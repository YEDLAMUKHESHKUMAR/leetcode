class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int mini = 0;
        // cout<<End;
        sort(intervals.begin(), intervals.end());
        int End = intervals[0][1];
        for(int i = 1; i<n;i++){
            if(intervals[i][0] < End){
                mini++;
                End = min(End, intervals[i][1]);
                // cout<<End<<" ";
            }
            else End = max(End, intervals[i][1]);
        }
        return mini;
    }
};