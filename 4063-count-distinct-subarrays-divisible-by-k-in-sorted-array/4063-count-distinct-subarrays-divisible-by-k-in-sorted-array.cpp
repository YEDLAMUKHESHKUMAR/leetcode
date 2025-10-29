#define ll long long
class Solution {
public:
    long long bs(ll target, vector<ll>& arr){
        ll ans = INT_MAX;
        ll n = arr.size();
        ll low = 0 , high = n - 1;
        while(low <= high){
            ll mid = (low + high) / 2;
            if(arr[mid] <= target){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(ans == INT_MAX) return 0;
        return ans + 1;
    }
    long long numGoodSubarrays(vector<int>& nums, int k) {
        ll n = nums.size();
        unordered_map<ll,ll> firstSeen;
        unordered_map<ll,vector<ll>> mp;
        vector<ll> prefix(n , 0);
        ll sum = 0;
        for(int i = 0; i < n ;i++){
            sum += nums[i];
            prefix[i] = (sum % k);
            // cout<<(sum % k )<<" ";
        }
        ll ans = 0;
        
        for(int i = 0; i < n; i++){
            if(prefix[i] == 0) ans++;
            ll targetInd = 1LL * i;
            if(firstSeen.find(nums[i]) != firstSeen.end()){
                targetInd = firstSeen[nums[i]] - 1;
            }
            else{
                firstSeen[nums[i]] = i;
            }
            if(mp.find(prefix[i]) != mp.end()){
                // cout<<i<<" "<<targetInd<<" "<<mp[prefix[i]].size()<<endl;
                if(targetInd != -1 ) ans +=  bs(targetInd, mp[prefix[i]]);
            }
            

            mp[prefix[i]].push_back(i);
        }
        return ans;
        
    }
};