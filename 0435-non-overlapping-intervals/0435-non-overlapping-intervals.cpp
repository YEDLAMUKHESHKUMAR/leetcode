class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int temp=0;
        int ans=0;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<intervals[temp][1]){
                ans++;
                if(intervals[i][1]<intervals[temp][1]){
                    temp=i;
                }
            }
            else{
                temp=i;
            }
        }
        return ans;
    }
};