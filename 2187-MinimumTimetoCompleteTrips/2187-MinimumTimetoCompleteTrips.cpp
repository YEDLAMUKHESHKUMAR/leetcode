#define ll long long 
class Solution {
public:
    bool solve(ll t, vector<int> &time, ll totalTrips){
        ll n = time.size();
        for(ll i = 0; i<n;i++){
            totalTrips -= (t / time[i]);
        }
        if(totalTrips <= 0) return true;
        return false;

    }
    ll minimumTime(vector<int>& time, int totalTrips) {
        // notes.....  intitution : we can use smallest time taken bus to complete total trips, but, we try to minimize the time , right, we will decrease one from the maxTime taken...see if we can make it...if yes decrease more...
        // nothing but binary search, we will see if we can complete the totalTrips in x seconds...if yes, we can easily complete the total trips in more than x seconds...so try to decrease x..
        ll n = time.size();
        sort(time.begin(), time.end());
        ll l = 0, h = 1LL * time[n-1] * totalTrips ;
        // return solve(1LL * 100, time, 1LL * totalTrips) == true ? 100 : 0;
        ll ans = 0;
        while(l <= h){
            ll mid = (l + h ) /2;
            // cout<<mid<<endl;
            if(solve(mid, time, totalTrips)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }  
        return ans;
    }
};