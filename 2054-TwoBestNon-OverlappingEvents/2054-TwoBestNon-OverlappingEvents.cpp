// Last updated: 4/17/2025, 3:43:09 PM
#define ll long long
class Solution {
public:
    ll bs(ll tar, vector<pair<ll,ll>> &st){
        ll n = st.size();
        ll low = 0, high = n - 1, ans = -1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(st[mid].first >= tar){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        // 1 10, 2 3 , 5 6  
        ll n = events.size();
        vector<pair<ll, ll>> st;
        sort(events.begin(), events.end());
        for(int i = 0; i < n ;i++){
            st.push_back({events[i][0], events[i][2]});
        }
        sort(st.begin(), st.end());
        ll maxi = 0, sum = 0;
        for(int i = n - 1; i >= 0; i--){
            maxi = max(maxi, st[i].second);
            st[i].second = maxi;
        }

        for(int i = 0; i< n ;i++){
            ll findSt = events[i][1] + 1;
            ll ind = bs(findSt, st);
            if(ind != -1){
                sum = max(sum, events[i][2] + st[ind].second);
            }
            else sum = max(sum, 1LL * events[i][2]);
        }
        return sum;

        

       

    }
};