#define ll long long
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
    int mostBooked(int m, vector<vector<int>>& meetings) {
        ll n =  meetings.size();
        priority_queue<ll, vector<ll>, greater<ll> > freeRooms;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > endTime;
        unordered_map<ll,ll> mp;
        for(ll i = 0; i < m; i++){
            freeRooms.push(i);
        }
        // return freeRooms.size();
        ll maxMeetings = 0;
        sort(meetings.begin(), meetings.end());
        for(ll i = 0; i < n ;i++){
            ll st = meetings[i][0], end = meetings[i][1];
            while(!endTime.empty() && st >= endTime.top().first) {
                ll freeNow = endTime.top().second;
                endTime.pop();
                freeRooms.push(freeNow);

            }

            if(!freeRooms.empty()){
                ll free = freeRooms.top();
                freeRooms.pop();
                endTime.push({end, free });
                mp[free]++;
                maxMeetings = max(maxMeetings, mp[free]);
            }
            else{
                ll endingAt = endTime.top().first;    
                
                ll willBeFree = endTime.top().second; 
                endTime.pop();
                ll currTotalMeetingTime = end - st;
                ll newEndingTime = endingAt + currTotalMeetingTime;
                endTime.push({newEndingTime, willBeFree});
                mp[willBeFree]++; 
                maxMeetings = max(maxMeetings, mp[willBeFree]);
            }

        }
        ll maxi = n;
        for(auto i : mp){
            // cout<<i.first<<" "<<i.second<<endl;
            if(i.second == maxMeetings){
                maxi = min(maxi, i.first);
            }
        }
        return maxi;
        


        


    }
};