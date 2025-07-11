// Last updated: 7/11/2025, 10:24:01 PM
#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // ll m = meetings.size();
        sort(meetings.begin(), meetings.end() );
        priority_queue< pair<ll, ll> ,  vector<pair<ll,ll>> , greater<pair<ll,ll>>> used;
        priority_queue< ll, vector<ll>, greater<ll> > notUsed;
        unordered_map<ll,ll> mp;

        for(int i = 0; i < n ;i++){
            notUsed.push(i);
        }

        for(auto meet : meetings){
            ll st = meet[0] ,end = meet[1];

            while(!used.empty() && used.top().first <= st){
                ll top = used.top().second;
                used.pop();
                notUsed.push(top);
            }

            if(!notUsed.empty()){
                ll unusedRoom = notUsed.top();
                notUsed.pop();
                used.push({ end, unusedRoom });
                mp[unusedRoom]++;
            }
            else{
                ll newSt = used.top().first;
                ll top = used.top().second;
                mp[top]++;
                used.pop();
                ll newEnd = newSt + (end - st);
                ll unusedRoom = notUsed.top();
                used.push({ newEnd, top });
            }



        }

        ll maxi = 0;
        for(ll i = 1; i < n; i++) {
            if(mp[i] > mp[maxi]) maxi = i;
        }
        return maxi;

    }
};