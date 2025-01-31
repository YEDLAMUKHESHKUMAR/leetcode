#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define pii pair<int,int>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = a ; i < b ; i++)
// #define rrep(i,a,b) for(int i = a ; i >= b ; i--)
#define N 1e6+1
 // -------------------------------------MATH-----------------------------------
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))

// -------------------------------------TEST CASE-------------------------
#define test int tc; cin>>tc; while(tc--)
#define narr ll n ; cin>>n; vi arr(n); rep(i , 0 , n) cin>>arr[i];
#define take(x) ll (x);cin>>(x);
#define takearr(name, size)  vl (name)(size); rep(i , 0 , size) cin>>(name)[i];
// -----------------------------DEBUG----------------------------------------
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printm(a) {for(auto u:a) cout<<u.F << " " << u.S<<endl;}
// ------------------------------------------------------------------
// #define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef set<int> si;
typedef map<int, int> mii;
const double eps = 1e-9;
const int mod = (int)1e9 + 7;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // 1  2  3   4   5   6   7  8  9  10   11 12 13 14 15 16 17 18 19 20
        // 2  4  6   8   9   9   9  9  11 13   15 
        // 7  7  7   7   7   7   7  9  11 13   14
        // 15 15 15  15  15  15 15 15  15 15   15

        //  [1,4,6,7,8,20], 
        //  [2,7,15]

        // trans :  dp[i][0] = cost[0] + min(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
        //          dp[i][1] = cost[1] + min(dp[i-7][0], dp[i-7][1], dp[i-7][2]); 
        //          dp[i][2] = cost[2] + min(dp[i-30][0], dp[i-30][1], dp[i-30][2]); 
        // we can reduce it to 1d dp , where dp[i - x ] stores the min (dp[i-x][0], dp[i-x][1], dp[i-x][2])
        // vector<vi> dp(366, vi (3, 0)); // no need...



        int n = days.size();
        vector<int> dp(366, 0);
        for(int i = 0; i<n;i++){
            for(int day = 1; day<= 365 ;day++){
                if(day > days[i]) break;

                if(dp[day] == 0){
                    dp[day] = dp[day - 1];  // these are not there in days....
                }
            }

            int currDay = days[i];
            dp[currDay] = costs[0] + dp[currDay - 1] ;
            dp[currDay] = min(dp[currDay], costs[1] + (dp[currDay >= 7 ? currDay - 7 : 0]));
            dp[currDay] = min(dp[currDay], costs[2] + dp[currDay >= 30 ? currDay - 30 : 0]);
        }
        return dp[days[n-1]];
        // return ;
    }
};