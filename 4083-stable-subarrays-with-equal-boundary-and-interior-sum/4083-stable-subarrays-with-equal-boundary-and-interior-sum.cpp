#define ll long long
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        ll n = capacity.size();
        unordered_map<ll, unordered_map<ll,ll>> mp;
        ll sum = 0;
        ll ans = 0;
        for(int i = 0 ; i < n ; i++){
            sum += capacity[i];
            ll element = capacity[i];
            ll target = sum  - (capacity[i]) - (capacity[i]);
            if(mp.find(target) != mp.end()){
                ll countt = mp[target][element];
                ans += countt;
                if(i > 0 && countt > 0){

                    if(element == 0 && capacity[i - 1] == 0 && (sum - capacity[i]) == (sum)) {
                        ans--;
                        // cout<<i<<" ";
                    }
                }
                // cout<<i<<" "<<mp[target].count(element)<<endl;
            }
            mp[sum][element]++;
        }
        return ans;
        
        // 0 0 0 0 0 0 0
        

    }
};