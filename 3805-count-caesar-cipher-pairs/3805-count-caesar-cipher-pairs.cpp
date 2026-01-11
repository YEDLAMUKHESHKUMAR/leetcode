#define ll long long
class Solution {
public:
    long long countPairs(vector<string>& words) {
        map< vector<ll>, ll> mp;
        ll ans = 0;
        for(auto s : words){
            vector<ll> arr;
            for(int i = 0; i < s.size() - 1; i++){
                arr.push_back((s[i + 1] - s[i] + 26) % 26);
            }
            ans += mp[arr];
            mp[arr]++;

        }
        return ans;
    }
};