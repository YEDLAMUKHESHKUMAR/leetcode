#define ll long long
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // notes :)
        int n = arr.size();
        unordered_map<ll,pair<ll,ll>> mp;
        ll x = 0, ans = 0;
        for(ll i = 0; i < n ;i++){
            x ^= arr[i];
            if(x == 0) ans += (i);
            if(mp.find(x) != mp.end()){
                ll size = mp[x].first;
                ll sum = mp[x].second;

                ans += ( ( i * size ) - sum - size  );   // :) optimization..
                cout<<ans<<endl;
            }
            mp[x].first++;
            mp[x].second += i;
        }
        for(auto i:mp){
            cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
        }
        return ans;

    }
};