// Last updated: 3/24/2025, 9:59:26 AM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int ans = max(0 , meetings[0][0] - 1), end = meetings[0][1] , n = meetings.size();
        for(int i = 1; i<n ;i++){
            if(meetings[i][0] > end){
                ans += (max(0, meetings[i][0] - end - 1 ));
                end  = meetings[i][1];
            }
            else{
                end = max(end, meetings[i][1]);
            }
        }
        ans += (days - end);
        return ans;

    }
};