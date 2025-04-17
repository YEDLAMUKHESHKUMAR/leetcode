// Last updated: 4/17/2025, 3:53:39 PM
#define ll long long
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        ll n = events.size();
        ll maxSum = 0, ans = 0, st , end, currSum ; // :)
        sort(events.begin(), events.end());
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
        for(int i = 0; i < n ;i++){
            st = events[i][0];
            end = events[i][1];
            currSum = events[i][2];
            while(!pq.empty() && st > pq.top().first ){
                ll prevSums = pq.top().second;
                pq.pop();
                maxSum = max(maxSum, prevSums);
            }
            ans = max(ans, currSum + maxSum);
            pq.push({end, currSum});
        }
        return ans;
    }
};