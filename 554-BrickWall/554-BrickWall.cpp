#define ll long long
class Solution {
public:
/*
          1 2 2 1
          3 1 2
          1 3 2
          2 4
          3 1 2
          1 3 1 1


          1 3 5 6
          3 4 6
          1 4 6
          2 6
          3 4 6
          1 4 5 6


        */

    int leastBricks(vector<vector<int>>& wall) {
        
        int n = wall.size();
        unordered_map<ll,ll> mp;
        for(int i = 0; i<n;i++){
            ll sum = 0;
            for(int j = 0; j<wall[i].size() - 1;j++){
                sum += wall[i][j];  // thought of prefix and store sums in map...maybe works ?? yep worked.... :)
                mp[sum]++;
            }
        }
        ll ans = n;
        for(auto i : mp){
            ans = min(ans, n - i.second);
        }
        return ans;


    }
};